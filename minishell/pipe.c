/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:21:38 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/14 16:04:36 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*parse_pipe(t_token **tok)
{
	char	*line;
	t_token	*last;
	char	*s;

	line = (*tok)->content;
	last = *tok;
	if (last->type != TOK_UNPROCESSED)
		return (last);
	s = ft_strchr(line, '|');
	if (!s)
		return (last);
	if (s > line)
		last = token_insert(token_new(line, s - line, TOK_UNPROCESSED), &last);
	if (!last)
		return (0);
	last = token_insert(token_new(0, 0, TOK_PIPE), &last);
	if (!last)
		return (0);
	last = token_insert(token_new(s + 1, ft_strlen(s), TOK_UNPROCESSED), &last);
	if (!last)
		return (0);
	token_free(tok);
	return (last);
}

int	parse_pipes(t_token **tok)
{
	t_token	*last;

	last = parse_pipe(tok);
	if (!last)
		return (0);
	while (last)
	{
		if (last->type == TOK_UNPROCESSED && ft_strchr(last->content, '|'))
		{
			if (last->prev)
				tok = &last->prev->next;
			else
				tok = &last;
			last = parse_pipe(tok);
			if (!last)
				return (0);
			continue ;
		}
		last = last->next;
	}
	return (1);
}
