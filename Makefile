NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c

OBJS = $(SRC:.c=.o)

RM = rm -rf

$(NAME) : $(OBJS)
	ar rcs -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all clean

.PHONY: all clean fclean re