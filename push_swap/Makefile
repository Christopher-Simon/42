NAME =	push_swap
BNAME =	checker
CC=gcc
CFLAGS=	-Wall -Wextra -Werror -g3

SRCS=	srcs/push_swap/push_swap.c \
	srcs/init/stack_utils.c \
	srcs/actions/actions.c \
	srcs/actions/actions_2.c \
	srcs/actions/actions_3.c \
	srcs/init/verif.c \
	srcs/init/atol.c \
	srcs/algo/median.c \
	srcs/init/low_algo.c \
	srcs/algo/algo.c \
	srcs/algo/algo_2.c \
	srcs/algo/algo_utils.c \
	srcs/algo/direct_above.c \
	srcs/init/init_lst.c \

BSRCS=	srcs/checker/checker.c \
	srcs/init/stack_utils.c \
	srcs/actions/actions.c \
	srcs/actions/actions_2.c \
	srcs/actions/actions_3.c \
	srcs/init/verif.c \
	srcs/init/atol.c \
	srcs/algo/median.c \
	srcs/init/low_algo.c \
	srcs/algo/algo.c \
	srcs/algo/algo_2.c \
	srcs/algo/algo_utils.c \
	srcs/algo/direct_above.c \
	srcs/init/init_lst.c \

RM= rm -f
OBJ= $(SRCS:.c=.o)
BOBJ= $(BSRCS:.c=.o)

INCS= -I includes -I my_lib/includes
MY_LIB= my_lib/lib_my.a

all : $(MY_LIB) $(NAME)

bonus : $(MY_LIB) $(BNAME)

$(NAME) :  $(OBJ) 
	$(CC) $(CFLAGS) -L my_lib $(OBJ) -o $@ $(INCS) -l_my

$(BNAME) : $(BOBJ)
	$(CC) $(CFLAGS) -L my_lib $(BOBJ) -o $@ $(INCS) -l_my

.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 

my_lib/lib_my.a:
	make -C my_lib all

clean :	
	$(RM) $(OBJ) $(BOBJ)
	make -C my_lib clean

fclean : clean
	$(RM) $(NAME) $(BNAME)
	$(RM) my_lib/lib_my.a

re : 	
		make fclean
		make all

.PHONY : all clean fclean re bonus
