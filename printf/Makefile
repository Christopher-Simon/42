NAME = libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=

BONUS=

RM= rm -f
OBJS= $(SRCS:.c=.o)
BNS= $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $^

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean :
	$(RM) $(OBJS) $(BNS)

fclean : clean
	$(RM) $(NAME)

re :	fclean all

.PHONY : all clean fclean re bonus