NAME =	ft_containers

FLAGS =	-Wall -Wextra -Werror -MMD -std=c++98

SRCS =	tester/main.cpp\
		tester/vector_test.cpp\
		tester/map_tests.cpp\
		tester/stack_tests.cpp

OBJS =	${SRCS:.cpp=.o}

all : $(NAME)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(NAME)

test : $(NAME)
	clang++ $(FLAGS) -D LIB="std" $(SRCS) -o std_containers
	./$(NAME) > ft_out
	./std_containers > std_out
	diff ft_out std_out

clean	: 
	rm -f $(OBJS)

fclean  :		clean
	rm -rf $(NAME)
	rm -rf std_containers
	rm  -f std_out ft_out
		

re	  : 		fclean all

.PHONY  : 		all fclean re
