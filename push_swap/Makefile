NAME =	push_swap
CC=gcc
CFLAGS=	-Wall -Wextra -Werror -g3

SRCS=	push_swap.c \
	stack_utils.c \
	actions.c \
	s_actions.c \
	utils.c \
	calcul.c \
	low_algo.c \

RM= rm -f
OBJ= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :	
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : 	
		$(MAKE) fclean
		$(MAKE) all

.PHONY : all clean fclean re bonus
