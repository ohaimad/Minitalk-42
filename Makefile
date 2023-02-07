CNAME = client
SNAME = server

CFLAGS = -Wall -Wextra -Werror

SRCS = client.c server.c \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = message_bonus

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
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) 

re:  fclean all

# bonus : $(BONUS_OBJS) $(OBJS)
# 	$(NAME)	$(BONUS_OBJS) $(OBJS)