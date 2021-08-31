NAME =	ft_containers

FLAGS =  -Wall -Wextra -Werror -std=c++98

SRCS =		main.cpp

OBJS =		${SRCS:.cpp=.o}


all : 			$(NAME)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

$(NAME) :	$(OBJS)
			clang++  $(FLAGS) $(OBJS) -o $(NAME)

clean	: 
				rm -f $(OBJS)

fclean  :		clean
				rm -rf $(NAME)
		

re	  : 		fclean all

.PHONY  : 		all fclean re