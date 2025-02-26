LIBNAME = libftgnl.a
MINILIB = minilibx-linux/libmlx.a

CC = cc
CFLAGS = -Wall  -Wextra

LIBDIR = ./Libraries

SRCS = main.c windows.c read_points.c math_1.c
INCLUDE = fdf.h

NAME = fdf

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Solo compila libft si la librería no existe
$(LIBDIR)/$(LIBNAME):
	@if [ ! -f "$@" ]; then make -C $(LIBDIR); fi

$(NAME): $(OBJS) $(LIBDIR)/$(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR)/$(LIBNAME) $(MINILIB) -fsanitize=address -g -lX11 -lXext -lm -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME) $(LIBDIR)/$(LIBNAME)
	@make -C $(LIBDIR) fclean

re: fclean all