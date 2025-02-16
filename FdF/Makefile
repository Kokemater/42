LIBNAME = libftgnl.a
LIBFTNAME = libft.a
GNLNAME = gnl.a
MINILIB = minilibx-linux/libmlx.a


CC = cc
CFLAGS = -Wall -Werror -Wextra


GNLDIR = ./get_next_line
LIBFTDIR = ./Libft

SRCS = 	main.c windows.c

INCLUDE = fdf.h

NAME = fdf


OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)						# Cambia directorio a libft y ejecuta make
	@cp $(LIBFTDIR)/$(LIBFTNAME) $(LIBNAME)		# Copia libft.a al directorio actual
	
makegnl:
	@make -C $(GNLDIR)
	@ar -r $(LIBNAME) $(GNLDIR)/$(GNLNAME)			


$(NAME): makelibft makegnl $(OBJS)
	cc $(CFLAGS)  $(LIBNAME) $(OBJS) -lX11 -lXext $(MINILIB) -o $(NAME)
	# @ar -r $(NAME) $(OBJS)				#Crea libft.a a partir de los objs

clean:
	@rm -f $(OBJS)						#Elimina los objs del directorio actual
	@cd $(LIBFTDIR) && make clean		#Elimina los objs del libft
	@cd $(GNLDIR) && make clean		#Elimina los objs del gnl

	
fclean: clean
	@rm -f $(NAME)						#Elimina el .a del directorio actual
	@cd $(LIBFTDIR) && make fclean		#Elimina el .a del libft
	@cd $(GNLDIR) && make fclean		#Elimina el .a del gnl

	
re: fclean all

