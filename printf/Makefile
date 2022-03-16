NAME =	printf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=	ft_printf.c\
	utils/size.c\
	utils/ft_convert_base.c\
	utils/ft_convert_base2.c\
	utils/ft_itoa_long.c\
	utils/ft_dec_to_hex.c\
	utils/ft_get_flags.c\
	flags/ft_c_flag.c\
	flags/ft_s_flag.c\
	flags/ft_p_flag.c\
	flags/ft_d_flag.c\
	libft/ft_itoa.c\
	libft/ft_putchar_fd.c\
	libft/ft_putstr_fd.c\
	libft/ft_strlen.c\
	libft/ft_isalpha.c\
	libft/ft_isdigit.c\
	libft/ft_memset.c\
	libft/ft_atoi.c\
	libft/ft_strchr.c\
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
