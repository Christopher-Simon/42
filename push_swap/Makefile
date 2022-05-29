NAME =	push_swap
BNAME =	checker
CC=gcc
CFLAGS=	-Wall -Wextra -Werror -g3

SRCS=	push_swap.c \
	stack_utils.c \
	actions.c \
	s_actions.c \
	utils.c \
	calcul.c \
	low_algo.c \
	algo.c \
	verif.c \
	algo_utils.c \
	direct_above.c \
	get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c \

BSRCS=	checker.c \
	stack_utils.c \
	actions.c \
	s_actions.c \
	utils.c \
	calcul.c \
	low_algo.c \
	algo.c \
	verif.c \
	algo_utils.c \
	direct_above.c \
	get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c \

RM= rm -f
OBJ= $(SRCS:.c=.o)
OBJS= $(BSRCS:.c=.o)

all : $(NAME)

bonus : $(BNAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $@ 

$(BNAME) : $(OBJS)
	$(CC) $(OBJS) -o $@ 

%.o : %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=5 -c $< -o $@

clean :	
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : 	
		$(MAKE) fclean
		$(MAKE) all

.PHONY : all clean fclean re bonus
