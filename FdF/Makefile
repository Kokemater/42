LIBNAME = libftgnl.a
MINILIB = minilibx-linux/libmlx.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBDIR = ./Libraries

SRCS = main.c windows.c read_points.c math_1.c
NAME = fdf
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBNAME):
	@make -C $(LIBDIR)
	@cp -n $(LIBDIR)/$(LIBNAME) .  

$(NAME): $(OBJS) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) $(MINILIB) -fsanitize=address -g -lX11 -lXext -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@cd $(LIBDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBDIR) && make fclean

re: fclean all
