SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
CFLAGS = -Wall -Werror -Wextra
$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)
%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
