/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:16:05 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/15 12:47:25 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redir_in(t_cmd *cmd, char *filename, int type)
{
	if (cmd->in > 2)
		close(cmd->in);
	cmd->in = open_file(filename, type);
}

static void	redir_out(t_cmd *cmd, char *filename, int type)
{
	if (cmd->out > 2)
		close(cmd->out);
	cmd->out = open_file(filename, type);
}

static int	redir_heredoc(t_cmd *cmd, char *del, t_minishell *ms)
{
	char	*input;
	char	*interpreted;

	if (cmd->in > 2)
		close(cmd->in);
	input = heredoc_read(del);
	interpreted = replace_vars(input, ms);
	cmd->in = heredoc_pipe(interpreted);
	if (input)
		free(input);
	if (interpreted)
		free(interpreted);
	return (1);
}

int	cmd_handle_redir(t_token **tok, t_cmd *cmd, t_minishell *ms)
{
	int	type;

	type = (*tok)->type;
	if (!check_next_literal(tok))
		return (2);
	if (type == TOK_REDIR_IN)
		redir_in(cmd, (*tok)->content, type);
	else if ((type == TOK_REDIR_OUT || type == TOK_REDIR_APPEND)
		&& cmd->excode == 0)
		redir_out(cmd, (*tok)->content, type);
	else if (type == TOK_REDIR_HEREDOC)
		if (!redir_heredoc(cmd, (*tok)->content, ms))
			return (0);
	if ((cmd->in < 0 || cmd->out < 0) && cmd->excode == 0)
	{
		perror("redirect");
		cmd->excode = 1;
	}
	return (1);
}
