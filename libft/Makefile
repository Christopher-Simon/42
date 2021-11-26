NAME =	libft.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS=	ft_isprint.c \
	ft_striteri.c \
	ft_strtrim.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_strjoin.c \
	ft_substr.c \
	ft_bzero.c \
	ft_putendl_fd.c \
	ft_strlcpy.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_strlen.c \
	ft_toupper.c \
	ft_isalnum.c \
	ft_memcmp.c \
	ft_putstr_fd.c \
	ft_strmapi.c \
	ft_isalpha.c \
	ft_memcpy.c \
	ft_split.c \
	ft_strncmp.c \
	ft_isascii.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strnstr.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_strdup.c \
	ft_strrchr.c

RM= rm -f
OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^
$(OBJS) :
	$(CC) $(CFLAGS) -c $(SRCS) 
clean :	
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : 	fclean all
