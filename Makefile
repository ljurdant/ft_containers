NAME =	containers

FLAGS =  -Wall -Wextra -Werror -std=c++98

SRCS =		srcs/main.cpp\
			srcs/vector.hpp\
			srcs/map.hpp\
			srcs/stack.hpp

OBJS =		${SRCS:.cpp=.o}

all : 			$(NAME)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

$(NAME) :	$(OBJS)
			clang++ $(FLAGS) $(OBJS) -o ft_$(NAME)

test :		$(NAME)
			clang++ $(FLAGS) -D LIB="std" $(SRCS) -o std_$(NAME)
			./ft_$(NAME) > ft_out
			./std_$(NAME) > std_out
			diff ft_out std_out


clean	: 
				rm -f $(OBJS)

fclean  :		clean
				rm -rf ft_$(NAME)
				rm -rf std_$(NAME)
				rm  -f std_out ft_out
		

re	  : 		fclean all

.PHONY  : 		all fclean re