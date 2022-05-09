NAME =	fractol
CC=gcc
CFLAGS= -Wall -Wextra -Werror -g3

LINK= -lmlx -lXext -lX11
MLX= ./minilibx-linux

SRCS=	main.c \

RM= rm -f
OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

.o : .c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ 

clean :	
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : 	fclean all

.PHONY : all clean fclean re bonus
