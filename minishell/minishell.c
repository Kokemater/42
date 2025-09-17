/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:42:00 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/15 13:14:17 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_line(char *line, t_minishell *ms)
{
	if (!token_insert(token_new(line, ft_strlen(line), TOK_UNPROCESSED),
			&ms->token))
		return (0);
	if (!parse_literals(&ms->token))
		return (0);
	if (!parse_pipes(&ms->token))
		return (0);
	if (!parse_redirs(&ms->token))
		return (0);
	if (!parse_vars(&ms->token, ms))
		return (0);
	if (!parse_separators(&ms->token))
		return (0);
	if (!merge_literals(&ms->token))
		return (0);
	if (!remove_empty_literals(&ms->token))
		return (0);
	if (!check_pipe_syntax(&ms->token))
		return (err_str("syntax error near pipe\n"),
			ms->excode = 2, 0);
	return (1);
}

void	minishell_free(t_minishell *ms)
{
	rl_clear_history();
	tab_free(ms->env);
}

void	minishell_free_line(t_minishell *ms)
{
	while (ms->token)
		token_free(&ms->token);
	cmd_free(&ms->cmd);
}

int	process_line(char *line, t_minishell *ms)
{
	if (*line && parse_line(line, ms))
	{
		if (cmd_build(ms))
		{
			if (cmd_exec(ms) != 0)
			{
				minishell_free_line(ms);
				free(line);
				return (0);
			}
		}
	}
	minishell_free_line(ms);
	return (1);
}

int	main(int argc, char *argv[], char *env[])
{
	t_minishell	ms;
	char		*line;

	(void)argc;
	(void)argv;
	if (!minishell_init(env, &ms))
		return (1);
	line = minishell_read();
	while (line && ms.exit == 0)
	{
		if (!ft_issspace(line))
			add_history(line);
		if (!process_line(line, &ms))
			break ;
		free(line);
		line = minishell_read();
	}
	minishell_free(&ms);
	return (ms.excode);
}
