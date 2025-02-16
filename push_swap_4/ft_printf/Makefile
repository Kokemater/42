NAME = libftprintf.a
LIBFTNAME = libft.a


CC = cc
CFLAGS = -Wall -Werror -Wextra


LIBFTDIR = ./libft
SRCS = 	ft_printf.c \
print_hexadecimal.c \
print_number.c \
print_text.c \

INCLUDE = ft_printf.h


OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)				# Cambia directorio a libft y ejecuta make
	@cp $(LIBFTDIR)/$(LIBFTNAME) .		# Copia libft.a al directorio actual
	@mv $(LIBFTNAME) $(NAME)			# Renombra libft.a a libftprintf.a

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)				#Crea makelibft.a a partir de los objs

clean:
	@rm -f $(OBJS)						#Elimina los objs del directorio actual
	@cd $(LIBFTDIR) && make clean		#Elimina los objs del libft
	
fclean: clean
	@rm -f $(NAME)						#Elimina el .a del directorio actual
	@cd $(LIBFTDIR) && make fclean		#Elimina el .a del libft
	
re: fclean all

