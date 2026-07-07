NAME		= philo

SRC			=	main.c \
				parser.c \
				init.c \
				clean.c \
				print.c \
				ts_utils.c \
				routine.c \
				threads.c \
				monitor.c
OBJS		 =	$(SRC:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re