NAME =	containers

FLAGS =  -Wall -Wextra -Werror -std=c++98

SRCS =		tester/main.cpp\
			tester/vector_test.cpp\
			tester/map_tests.cpp\
			tester/stack_tests

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