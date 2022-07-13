CC = gcc
CFLAGS = -Wall -Wextra -Werror
MANDATORY = get_next_line_utils.c\
			get_next_line.c

MAN_OBJS = $(MANDATORY:.c=.o)
NAME = gnl.a

all: $(NAME)

$(NAME): $(MAN_OBJS)
	ar r $(NAME) $(MAN_OBJS)

clean:
	rm -f $(MAN_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus