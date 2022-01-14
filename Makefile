NAME =	ft_containers


LIST =	main\
		vector_test\
		map_tests\
		stack_tests

HEADER	=	-I includes/
CFLAGS =	-Wall -Wextra -Werror -MMD -std=c++98
CC		=	clang++

S_DIR	=	srcs/
I_DIR	=	includes/
O_DIR	=	objs/
D_DIR	=	deps/

C_SUFF	=	.cpp
O_SUFF	=	.o
D_SUFF	=	.d

DIR_O	=	@mkdir -p objs/
DIR_D	=	@mkdir -p deps/

RM_FILE	= rm -f
RM_DIR	= rm -rf

LIST_C	= $(addprefix $(S_DIR), $(LIST))
LIST_O	= $(addprefix $(O_DIR), $(LIST))
LIST_D	= $(addprefix $(D_DIR), $(LIST))

SRCS	= $(addsuffix $(C_SUFF), $(LIST_C))
OBJS	= $(addsuffix $(O_SUFF), $(LIST_O))
DEPS	= $(OBJS:.o=.d)

$(O_DIR)%.o	:	$(S_DIR)%.cpp
				$(DIR_O)
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME)	:		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all	:			$(NAME)


test : $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -D LIB="std"  -o std_containers
	./$(NAME) > ft_out
	./std_containers > std_out
	diff ft_out std_out

clean	:		
				$(RM_DIR) $(O_DIR) $(D_DIR)

fclean	: clean
		$(RM_FILE) $(NAME)
		rm -rf std_containers
		rm  -rf std_out ft_out
		
re	  : 		fclean all

.PHONY  : 		all fclean re

-include	$(DEPS)