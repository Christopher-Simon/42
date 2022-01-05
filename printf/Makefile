<<<<<<< HEAD
NAME =	printf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=	ft_printf.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_strlen.c\
	main.c
BONUS=	
=======
NAME = libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=

BONUS=
>>>>>>> fb809d5bb07cef213739b9072b9d12535dd19016

RM= rm -f
OBJS= $(SRCS:.c=.o)
BNS= $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
<<<<<<< HEAD
	ar -rcs $@ $^

bonus : $(OBJS) $(BNS)
	ar -rcs $(NAME) $^ 
=======
	ar -rcs $(NAME) $^
>>>>>>> fb809d5bb07cef213739b9072b9d12535dd19016

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

<<<<<<< HEAD
clean :	
=======
clean :
>>>>>>> fb809d5bb07cef213739b9072b9d12535dd19016
	$(RM) $(OBJS) $(BNS)

fclean : clean
	$(RM) $(NAME)

<<<<<<< HEAD
re : 	fclean all
=======
re :	fclean all
>>>>>>> fb809d5bb07cef213739b9072b9d12535dd19016

.PHONY : all clean fclean re bonus
