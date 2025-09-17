/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:10:12 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/14 12:36:53 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_new(t_cmd	**cmd)
{
	t_cmd	*res;
	t_cmd	*it;

	res = malloc(sizeof(t_cmd));
	if (!res)
		return (0);
	res->in = 0;
	res->out = 1;
	res->next = 0;
	res->args = 0;
	res->excode = 0;
	res->pid = -1;
	it = *cmd;
	while (it && it->next)
		it = it->next;
	if (it)
		it->next = res;
	else
		*cmd = res;
	return (res);
}

void	cmd_free(t_cmd **cmd)
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
	while (*cmd)
	{
		tmp = *cmd;
		tab_free(tmp->args);
		*cmd = tmp->next;
		free(tmp);
	}
	*cmd = 0;
}

static int	cmd_process_tok(t_cmd *cmd, t_token **tok, t_minishell *ms)
{
	int	ret;

	if ((*tok)->type >= TOK_REDIR_IN && (*tok)->type <= TOK_REDIR_APPEND)
	{
		ret = cmd_handle_redir(tok, cmd, ms);
		if (ret == 0)
			return (ms->excode = 1, 0);
		if (ret == 2)
			return (ms->excode = 2, 0);
	}
	else if ((*tok)->type < TOK_SEPARATOR && !cmd->args)
	{
		if (!build_args(*tok, cmd))
			return (0);
	}
	else if ((*tok)->type == TOK_PIPE)
		return (2);
	return (1);
}

static int	cmd_from(t_token **tok, t_minishell *ms)
{
	t_cmd	*cmd;
	int		res;

	cmd = cmd_new(&ms->cmd);
	if (!cmd)
		return (0);
	while (*tok)
	{
		res = cmd_process_tok(cmd, tok, ms);
		if (res == 0)
			return (0);
		if (*tok)
			*tok = (*tok)->next;
		if (res == 2)
			break ;
	}
	return (1);
}

int	cmd_build(t_minishell *ms)
{
	t_token	*it;

	it = ms->token;
	while (it)
	{
		if (!cmd_from(&it, ms))
			return (0);
	}
	return (1);
}
