SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror

NAME = gnl.a
INCLUDE = get_next_line.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	rm -f $(BONUS_CACHE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
