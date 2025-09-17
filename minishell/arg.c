/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:40:20 by dmoraled          #+#    #+#             */
/*   Updated: 2025/05/29 13:10:48 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	arg_n(t_token *tok)
{
	int	i;

	i = 0;
	while (tok && tok->type != TOK_PIPE)
	{
		if (tok->type < TOK_SEPARATOR)
			++i;
		if (tok->type >= TOK_REDIR_IN && tok->type <= TOK_REDIR_APPEND)
			tok = next_literal(tok);
		if (tok)
			tok = tok->next;
	}
	return (i);
}

int	build_args(t_token *tok, t_cmd *cmd)
{
	t_token	*it;
	int		i;

	i = arg_n(tok);
	cmd->args = malloc(sizeof(char *) * (i + 1));
	if (!cmd->args)
		return (0);
	it = tok;
	cmd->args[i] = 0;
	i = 0;
	while (it && it->type != TOK_PIPE)
	{
		if (it->type < TOK_SEPARATOR)
		{
			cmd->args[i++] = it->content;
			it->content = 0;
		}
		if (it->type >= TOK_REDIR_IN && it->type <= TOK_REDIR_APPEND)
			it = next_literal(it);
		if (it)
			it = it->next;
	}
	return (1);
}
