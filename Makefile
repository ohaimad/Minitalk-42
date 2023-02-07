CNAME = client
SNAME = server
CNAME_B = client_b
SNAME_B = server_b

CFLAGS = -Wall -Wextra -Werror

SRCS = client.c server.c \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = server_bonus.c client_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADER = minitalk.h

all: PRINTF $(CNAME) $(SNAME)

CC = cc

PRINTF:
	make -C printf

$(CNAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) client.c printf/libftprintf.a -o client

$(SNAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) server.c printf/libftprintf.a -o server

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(OBJS) $(CNAME) $(SNAME)

re:  fclean all

bonus : PRINTF $(CNAME_B) $(SNAME_B)

$(CNAME_B) : $(BONUS_OBJS) $(HEADER)
	$(CC) $(CFLAGS) client_bonus.c printf/libftprintf.a -o client_b

$(SNAME_B) : $(BONUS_OBJS) $(HEADER)
	$(CC) $(CFLAGS) server_bonus.c printf/libftprintf.a -o server_b