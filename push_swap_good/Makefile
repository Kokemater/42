
SRC =  lists_funcs_3.c order.c order_next_to.c \
      helper_funcs.c lists_funcs_4.c order_elementary.c order_move3.c \
      helper_funcs2.c helper_funcs3.c main.c order_moves.c \
      inspect_errors.c moves_1.c order_moves2.c \
      lists_funcs.c moves_2.c order_n_moves.c create_list.c \
      lists_funcs_2.c read_argv.c read_argv2.c free_arr.c

OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
INCLUDE = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -fsanitize=address -g $(OBJ) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
