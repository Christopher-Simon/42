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
MY_LIB= my_lib/my_lib.a

all : $(MY_LIB) $(SERVER) $(CLIENT)

bonus : $(MY_LIB)

$(SERVER) :  $(OSERVER) 
	$(CC) $(CFLAGS) -L my_lib $(OSERVER) -o $@ $(INCS) -l_my

$(CLIENT) : $(OCLIENT)
	$(CC) $(CFLAGS) -L my_lib $(OCLIENT) -o $@ $(INCS) -l_my

.c.o :
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 

my_lib/my_lib.a:
	make -C my_lib all

clean :	
	$(RM) $(OSERVER) $(OCLIENT)
	make -C my_lib clean

fclean : clean
	$(RM) $(SERVER) $(CLIENT)
	$(RM) my_lib/my_lib.a

re : 	
		make fclean
		make all

.PHONY : all clean fclean re bonus
