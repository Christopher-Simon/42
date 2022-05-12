NAME =	fractol
CC=gcc
CFLAGS=	-Wall -Wextra -Werror -g3 -Ofast

SRCS=	fractol.c \
	mandelbrot.c \
	burning_ship.c \
	julia.c \
	utils.c \
	hook.c \


RM= rm -f
OBJ= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :	
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : 	
		$(MAKE) fclean
		$(MAKE) all

testm:
		$(MAKE) re
		./fractol mandelbrot

testj:
		$(MAKE) re
		./fractol julia
testn:
		$(MAKE) re
		./fractol burning_ship
testi:
		$(MAKE) re
		env -i valgrind ./fractol mandelbrot
testv:
		$(MAKE) re
		valgrind ./fractol mandelbrot

.PHONY : all clean fclean re bonus
