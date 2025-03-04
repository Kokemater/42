LIBNAME = libft.a

CC = cc
CFLAGS = -Wall  -Wextra -Werror

LIBDIR = ./Libraries

SRCS = pipex.c utils.c
INCLUDE = pipex.h

NAME = pipex

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBDIR)/$(LIBNAME):
	make -C $(LIBDIR)

$(NAME): $(OBJS) $(LIBDIR)/$(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR)/$(LIBNAME) -fsanitize=address -g -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME) $(LIBDIR)/$(LIBNAME)
	@make -C $(LIBDIR) fclean

re: fclean all