SRC = megaphone.cpp\

	  
OBJ = $(SRC:.cpp=.o)

NAME = megaphone

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
INC = philo.h

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $@

%.o: %.c $(INC)
	c++ $(CPPFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
