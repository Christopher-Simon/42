NAME =	libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror -g3
SRCS=	utils/ft_printf.c\
	utils/size.c\
	utils/checker.c\
	utils/checker2.c\
	utils/ft_convert_base.c\
	utils/ft_convert_base2.c\
	utils/ft_itoa_long.c\
	utils/ft_dec_to_hex.c\
	utils/ft_get_flags.c\
	utils/ft_strcpy.c\
	flags/ft_c_flag.c\
	flags/ft_s_flag.c\
	flags/ft_p_flag.c\
	flags/ft_p_flag2.c\
	flags/ft_d_flag.c\
	flags/ft_d_flag2.c\
	flags/ft_i_flag.c\
	flags/ft_i_flag2.c\
	flags/ft_u_flag.c\
	flags/ft_u_flag2.c\
	flags/ft_x_flag.c\
	flags/ft_x_flag2.c\
	flags/ft_big_x_flag.c\
	flags/ft_big_x_flag2.c\
	libft/ft_itoa.c\
	libft/ft_putchar_fd.c\
	libft/ft_putstr_fd.c\
	libft/ft_strlen.c\
	libft/ft_isalpha.c\
	libft/ft_isdigit.c\
	libft/ft_memset.c\
	libft/ft_atoi.c\
	libft/ft_strchr.c\
	libft/ft_substr.c\
	libft/ft_strlcpy.c\
	libft/ft_calloc.c\
	libft/ft_bzero.c

RM= rm -f
OBJS= $(SRCS:.c=.o)
BNS= $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

bonus : $(OBJS) $(BNS)
	ar -rcs $(NAME) $^ 

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean :	
	$(RM) $(OBJS) $(BNS)

fclean : clean
	$(RM) $(NAME)

re : 	fclean all

.PHONY : all clean fclean re bonus
