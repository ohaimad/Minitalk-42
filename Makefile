CNAME = client
SNAME = server
CNAME_B = client_b
SNAME_B = server_b

CFLAGS = -Wall -Wextra -Werror

SRCS_C = client.c ft_atoi.c \

SRCS_S = server.c ft_atoi.c \

OBJS_C = $(SRCS_C:.c=.o)

OBJS_S = $(SRCS_S:.c=.o)

BONUS_SRCS_C = client_bonus.c ft_atoi.c \

BONUS_SRCS_S = server_bonus.c ft_atoi.c \

BONUS_OBJS_C = $(BONUS_SRCS_C:.c=.o)

BONUS_OBJS_S = $(BONUS_SRCS_S:.c=.o)

HEADER = minitalk.h

NAME = minitalk

PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(PRINTF) $(CNAME) $(SNAME)

CC = cc

$(PRINTF):
	make -C printf

$(CNAME) : $(OBJS_C) $(HEADER)
	$(CC) $(CFLAGS) $(PRINTF) client.c ft_atoi.c  -o client

$(SNAME) : $(OBJS_S) $(HEADER)
	$(CC) $(CFLAGS) $(PRINTF) server.c ft_atoi.c  -o server

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	make clean -C printf
	rm -f $(OBJS_C) $(OBJS_S) $(BONUS_OBJS_C) $(BONUS_OBJS_S)

fclean: clean
	make fclean -C printf
	rm -f $(CNAME) $(SNAME) $(CNAME_B) $(SNAME_B)

re:  fclean all

bonus : $(PRINTF) $(CNAME_B) $(SNAME_B)

$(CNAME_B) : $(BONUS_OBJS_C) $(HEADER)
	$(CC) $(CFLAGS) $(PRINTF) client_bonus.c ft_atoi.c  -o client_b

$(SNAME_B) : $(BONUS_OBJS_S) $(HEADER)
	$(CC) $(CFLAGS) $(PRINTF) server_bonus.c ft_atoi.c  -o server_b

.PHONY = all $(NAME) bonus clean fclean re