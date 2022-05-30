NAME =	push_swap
BNAME =	checker
CC=gcc
CFLAGS=	-Wall -Wextra -Werror -g3

SRCS=	push_swap.c \
	srcs/stack_utils.c \
	srcs/actions.c \
	srcs/actions_2.c \
	srcs/actions_3.c \
	srcs/verif.c \
	srcs/atol.c \
	srcs/median.c \
	low_algo.c \
	algo.c \
	algo_2.c \
	algo_utils.c \
	direct_above.c \
	init_lst.c \

BSRCS=	checker.c \
	srcs/stack_utils.c \
	srcs/actions.c \
	srcs/actions_2.c \
	srcs/actions_3.c \
	srcs/verif.c \
	srcs/atol.c \
	srcs/median.c \
	low_algo.c \
	algo.c \
	algo_2.c \
	algo_utils.c \
	direct_above.c \
	init_lst.c \

RM= rm -f
OBJ= $(SRCS:.c=.o)
BOBJ= $(BSRCS:.c=.o)

INCS= -I includes -I my_lib/includes
MY_LIB= my_lib/my_lib.a

all : $(MY_LIB) $(NAME)

bonus : $(BNAME)

$(NAME) :  $(OBJ) 
	$(CC) $(CFLAGS) -L my_lib $(OBJ) -o $@ $(INCS) -l_my

$(BNAME) : $(BOBJ)
	$(CC) $(CFLAGS) -L my_lib $(BOBJ) -o $@ $(INCS) -l_my

.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 

my_lib/my_lib.a:
	make -C my_lib all

clean :	
	$(RM) $(OBJ) $(BOBJ)
	make -C my_lib clean

fclean : clean
	$(RM) $(NAME) $(BNAME)
	$(RM) my_lib/my_lib.a

re : 	
		make fclean
		make all

.PHONY : all clean fclean re bonus
