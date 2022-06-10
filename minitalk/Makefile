SERVER = server
CLIENT = client
CC= gcc
CFLAGS=	-Wall -Wextra -Werror -g3

SRCS_SERVER=	server.c

SRCS_CLIENT=	client.c

RM= rm -f
OSERVER= $(SRCS_SERVER:.c=.o)
OCLIENT= $(SRCS_CLIENT:.c=.o)

INCS= -I includes -I my_lib/includes
MY_LIB= my_lib/lib_my.a

all : $(MY_LIB) $(SERVER) $(CLIENT)

bonus : $(MY_LIB) $(SERVER) $(CLIENT)

$(SERVER) :  $(OSERVER)
	$(CC) $(CFLAGS) -L my_lib $(OSERVER) -o $@ $(INCS) -l_my

$(CLIENT) : $(OCLIENT)
	$(CC) $(CFLAGS) -L my_lib $(OCLIENT) -o $@ $(INCS) -l_my

.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

my_lib/lib_my.a:
	make -C my_lib all

clean :
	$(RM) $(OSERVER) $(OCLIENT)
	make -C my_lib clean

fclean : clean
	$(RM) $(SERVER) $(CLIENT)
	$(RM) my_lib/lib_my.a

re :
		make fclean
		make all

.PHONY : all clean fclean re bonus