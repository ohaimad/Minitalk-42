NAME = Minitalk

CFLAGS = -Wall -Wextra -Werror

SRCS = client.c server.c \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = 

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADER = minitalk.h

all: $(NAME)

CC = cc

$(NAME) : $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) client.c -o client
	$(CC) $(CFLAGS) server.c -o server

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) 

re:  fclean all

# bonus : $(BONUS_OBJS) $(OBJS)
# 	$(NAME)	$(BONUS_OBJS) $(OBJS)