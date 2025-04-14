SRC = Libft/ft_bzero.c \
	Libft/ft_isalnum.c \
	Libft/ft_isalpha.c \
	Libft/ft_isascii.c \
	Libft/ft_isdigit.c \
	Libft/ft_isprint.c \
	Libft/ft_memcmp.c \
	Libft/ft_memcpy.c \
	Libft/ft_memset.c \
	Libft/ft_memmove.c \
	Libft/ft_memchr.c \
	Libft/ft_strlen.c \
	Libft/ft_strnstr.c \
	Libft/ft_strchr.c \
	Libft/ft_strncmp.c \
	Libft/ft_strrchr.c \
	Libft/ft_strlcat.c \
	Libft/ft_strlcpy.c \
	Libft/ft_tolower.c \
	Libft/ft_toupper.c \
	Libft/ft_putchar_fd.c \
	Libft/ft_putendl_fd.c \
	Libft/ft_putstr_fd.c \
	Libft/ft_putendl_fd.c \
	Libft/ft_calloc.c \
	Libft/ft_strdup.c \
	Libft/ft_strjoin.c \
	Libft/ft_substr.c \
	Libft/ft_strtrim.c \
	Libft/ft_putnbr_fd.c \
	Libft/ft_itoa.c \
	Libft/ft_atoi.c \
	Libft/ft_striteri.c \
	Libft/ft_strmapi.c \
	Libft/ft_split.c \
	Libft/ft_split.c \
	Libft/ft_atoi.c \
	Libft/ft_substr.c \
	Libft/ft_atoi_hex.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS = Libft/ft_lstnew_bonus.c \
	Libft/ft_lstadd_front_bonus.c \
	Libft/ft_lstlast_bonus.c \
	Libft/ft_lstsize_bonus.c \
	Libft/ft_lstadd_back_bonus.c \
	Libft/ft_lstdelone_bonus.c \
	Libft/ft_lstclear_bonus.c \
	Libft/ft_lstiter_bonus.c \
	Libft/ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libftgnl.a
INCLUDE = Libft/libft.h
BONUS_CACHE = bonus.cache

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<

$(BONUS_CACHE): $(BONUS_OBJ) $(OBJ) $(INCLUDE)
	touch $(BONUS_CACHE)
	ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)

bonus: $(BONUS_CACHE)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	rm -f $(BONUS_CACHE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
