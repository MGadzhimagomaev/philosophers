NAME		= philo

SRC			= main.c \
				parser.c
SRC_PATH	= philo/
SRCS		+=	$(addprefix $(SRC_PATH), $(SRC))
OBJS		=	$(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:SRC_PATH
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re