/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:27:28 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/15 13:47:50 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_init(char *env[], t_minishell *ms)
{
	ms->env = env_dup(env);
	if (!ms->env)
		return (0);
	ms->token = 0;
	ms->cmd = 0;
	ms->excode = 0;
	ms->exit = 0;
	signal(SIGINT, sigint_idle);
	signal(SIGQUIT, SIG_IGN);
	return (1);
}

t_token	*next_literal(t_token *tok)
{
	if (!tok)
		return (0);
	tok = tok->next;
	while (tok)
	{
		if (tok->type > TOK_SEPARATOR)
			return (0);
		if (tok->type < TOK_SEPARATOR)
			return (tok);
		tok = tok->next;
	}
	return (0);
}

int	remove_empty_literals(t_token **tok)
{
	t_token	*it;

	it = *tok;
	while (it)
	{
		if (it->type == TOK_UNPROCESSED && it->content && !(*it->content))
		{
			if (it->prev)
			{
				token_free(&it->prev->next);
				it = 0;
			}
			else
			{
				token_free(tok);
				it = *tok;
			}
		}
		else
			it = it->next;
	}
	return (1);
}

int	open_file(char *filename, char type)
{
	int		fd;

	fd = -1;
	if (type == TOK_REDIR_IN)
		fd = open(filename, O_RDONLY);
	else if (type == TOK_REDIR_OUT)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else if (type == TOK_REDIR_APPEND)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0664);
	return (fd);
}

char	*minishell_read(void)
{
	char	*line;
	char	*trim;

	if (isatty(STDIN_FILENO))
		return (readline("ms$ "));
	else
	{
		line = get_next_line(STDIN_FILENO);
		trim = ft_strtrim(line, "\n");
		if (line)
			free(line);
		return (trim);
	}
}
