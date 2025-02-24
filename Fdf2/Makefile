LIBNAME = libftgnl.a
MINILIB = minilibx-linux/libmlx.a


CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBDIR = ./Libraries

SRCS = 	main.c windows.c read_points.c math_1.c
INCLUDE = fdf.h

NAME = fdf

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibftgnl:
	@make -C $(LIBDIR)						# Cambia directorio a libft y ejecuta make
	@cp $(LIBDIR)/$(LIBNAME) .				# Copia libft.a al directorio actual

$(NAME): makelibftgnl $(OBJS)
	cc $(CFLAGS)  $(OBJS) $(LIBNAME) $(MINILIB) -fsanitize=address -g -lX11 -lXext -lm -o $(NAME)
	# @ar -r $(NAME) $(OBJS)				

clean:
	@rm -f $(OBJS)						#Elimina los objs del directorio actual
	@cd $(LIBDIR) && make clean		#Elimina los objs del libft



fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBNAME)
	@cd $(LIBDIR) && make fclean		#Elimina el .a del libft

re: fclean all

