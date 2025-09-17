/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:14:41 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/15 13:48:02 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <termios.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <readline/history.h>
# include <readline/readline.h>

# include "libft/libft.h"

# define TOK_UNPROCESSED 0
# define TOK_LITERAL 1
# define TOK_INTLITERAL 2
# define TOK_SEPARATOR 3
# define TOK_REDIR_IN 4
# define TOK_REDIR_OUT 5
# define TOK_REDIR_HEREDOC 6
# define TOK_REDIR_APPEND 7
# define TOK_PIPE 8

# define SIGS_DEFAULT 0
# define SIGS_EXEC 1
# define SIGS_HEREDOC 2
# define SIGS_INT 3

typedef struct s_token
{
	char			type;
	char			*content;
	struct s_token	*next;
	struct s_token	*prev;
}		t_token;

typedef struct s_cmd
{
	char			**args;
	int				in;
	int				out;
	int				excode;
	int				pid;
	struct s_cmd	*next;
}		t_cmd;

typedef struct s_minishell
{
	char	**env;
	t_token	*token;
	t_cmd	*cmd;
	int		excode;
	int		exit;
}		t_minishell;

int		minishell_init(char *env[], t_minishell *ms);
void	minishell_exit(t_minishell *ms, int code);

char	*minishell_read(void);

char	*replace_vars(char *str, t_minishell *ms);
char	**path_from_env(char *env[]);
char	*var_from_env(char *var, char *env[]);
char	*find_exec_path(char *name, t_minishell *ms);
char	*ft_earlier(char *a, char *b);

void	tab_free(char **tab);
int		tab_length(char **tab);
int		tab_strlen(char **tab);
char	*tab_join(char **tab);
void	print_tab(char **tab);

void	err_open_literal(char literal);
void	err_str(char *str);
void	err_str2(char *s1, char *s2, int error);
int		check_next_literal(t_token **tok);
int		check_pipe_syntax(t_token **tok);

void	redirect_custom(t_cmd *cmd);
void	execute_builtin_or_external(t_cmd *cmd, t_minishell *ms);
int		handle_parent_pipe_management(int *prev_fd, int pipe_fd[2]);
int		builtin_alone(t_cmd *cmd, t_minishell *ms);
int		builtins_nofork(t_cmd *cmd, t_minishell *ms);
int		create_pipe(t_cmd *cmd, int pipe_fd[2], int *pid);
void	redirect_pipe(int *prev_fd, t_cmd *cmd, int pipe_fd[2]);
int		ft_issspace(char *s);

char	**env_dup(char **env);
char	**env_add(char **env, char *newvar);
char	**env_find(char *var, char **env);
int		env_set(char *var, char *val, t_minishell *ms);
int		env_remove(char *var, char **env);

t_token	*token_insert(t_token *n, t_token **to);
void	token_free(t_token **tok);
t_token	*token_new(char *content, int len, int type);
void	token_print(t_token *tok);

t_token	*next_literal(t_token *tok);
int		remove_empty_literals(t_token **tok);
int		parse_literals(t_token **tok);
int		merge_literals(t_token **tok);

int		parse_pipes(t_token **tok);
int		parse_redirs(t_token **tok);
int		parse_separators(t_token **tok);
int		parse_vars(t_token **tok, t_minishell *ms);
char	**var_split(char *str);

int		check_var_name(char *var);
char	*replace_exit_code(char *str, char excode);

int		open_file(char *filename, char type);
int		file_error(char *filename, int access_type);

int		cmd_build(t_minishell *ms);
void	cmd_free(t_cmd **cmd);
int		build_args(t_token *tok, t_cmd *cmd);
t_cmd	*cmd_last(t_cmd *cmd);
int		cmd_handle_redir(t_token **tok, t_cmd *cmd, t_minishell *ms);

int		heredoc_pipe(char *heredoc);
char	*heredoc_read(char *del);

pid_t	exec_program(char *cmd[], char *path[], char *env[]);
int		cmd_exec(t_minishell *ms);

void	sigint_exec(int sig);
void	sigint_heredoc(int sig);
void	sigint_idle(int sig);

// builtins
int		env_main(char **env);
int		export_main(char **argv, t_minishell *ms);
int		echo_main(char **args);
int		exit_main(char **args);
int		pwd_main(void);
int		cd_main(char **argv, t_minishell *ms);
int		unset_main(char **argv, t_minishell *ms);

#endif
