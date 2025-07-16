SRC = simulation.c\
	  philo.c\
	  util.c\
	  main.c
	  
OBJ = $(SRC:.c=.o)

NAME = philo

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
INC = philo.h

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $@

%.o: %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
