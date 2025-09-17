SRC = minishell.c\
	  signals.c\
	  utils.c\
	  var.c\
	  var_utils.c\
	  token.c\
	  literal.c\
	  pipe.c\
	  redir.c\
	  separator.c\
	  cmd.c\
	  cmd_redir.c\
	  heredoc.c\
	  arg.c\
	  error.c\
	  exec_utils.c\
	  exec.c\
	  tab.c\
	  env_utils.c\
	  builtin/env.c\
	  builtin/export.c\
	  builtin/pwd.c\
	  builtin/echo.c\
	  builtin/cd.c\
	  builtin/unset.c\
	  builtin/exit.c\
	  utils2.c\
	  exec_funcs.c\
	  exec_funcs2.c

OBJ = $(SRC:.c=.o)

NAME = minishell

LIBDIR = libft
LIB = $(LIBDIR)/libft.a
LIBFLAGS = -L$(LIBDIR) -lft

CFLAGS = -Wall -Wextra -Werror# -g3 -fsanitize=address
INC = pipex.h

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIBFLAGS) -lreadline -o $@

$(LIB):
	@$(MAKE) --no-print-directory -C $(LIBDIR)

%.o: %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) --no-print-directory -C $(LIBDIR) clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) --no-print-directory -C $(LIBDIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
