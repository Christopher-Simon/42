NAME =	printf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=	ft_printf.c\
	utils/size.c\
	libft/ft_putchar_fd.c\
	libft/ft_putstr_fd.c\
	libft/ft_strlen.c\
	libft/ft_isalpha.c\
	libft/ft_isdigit.c\
	libft/ft_memset.c\
	libft/ft_atoi.c\
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
