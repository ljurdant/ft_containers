NAME	=	test

SRCS	=	test.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC		=	clang++

FLAGS	=	-Wall -Werror -Wextra -g -std=c++98 

%.o:		%.cpp
			$(CC) $(FLAGS) -DVERSION=1 -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(ORIG)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all