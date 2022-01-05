NAME =	printf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=	ft_printf.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_strlen.c\
	main.c
BONUS=	

RM= rm -f
OBJS= $(SRCS:.c=.o)
BNS= $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

bonus : $(OBJS) $(BNS)
	ar -rcs $(NAME) $^ 

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean :	
	$(RM) $(OBJS) $(BNS)

fclean : clean
	$(RM) $(NAME)

re : 	fclean all

.PHONY : all clean fclean re bonus
