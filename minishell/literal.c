/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:29 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/12 13:25:41 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	literal_type(char literal)
{
	if (literal == '\'')
		return (TOK_LITERAL);
	else if (literal == '\"')
		return (TOK_INTLITERAL);
	return (TOK_UNPROCESSED);
}

int	merge_literals(t_token **tok)
{
	t_token	*it;
	char	*swp;

	it = *tok;
	while (it)
	{
		while (it->next && it->type < TOK_SEPARATOR
			&& it->next->type < TOK_SEPARATOR)
		{
			swp = ft_strjoin(it->content, it->next->content);
			if (!swp)
				return (0);
			free(it->content);
			it->content = swp;
			token_free(&it->next);
		}
		it = it->next;
	}
	return (1);
}

static t_token	*append_rest(t_token *last, char *s)
{
	char	*end;

	end = ft_strchr(s + 1, *s);
	if (!end)
		return (err_open_literal(*s), (t_token *)0);
	last = token_insert(token_new(s + 1, end - s - 1, literal_type(*s)), &last);
	if (!last)
		return (0);
	if (end[1] != 0)
		last = token_insert(token_new(end + 1, ft_strlen(end), TOK_UNPROCESSED),
				&last);
	return (last);
}

static t_token	*parse_literal(t_token **tok)
{
	char	*line;
	t_token	*last;
	char	*s;

	line = (*tok)->content;
	last = *tok;
	s = ft_earlier(ft_strchr(line, '\''), ft_strchr(line, '\"'));
	if (!s)
		return (last);
	if (s > line)
		last = token_insert(token_new(line, s - line, TOK_UNPROCESSED), &last);
	if (!last)
		return (0);
	last = append_rest(last, s);
	if (!last)
		return (0);
	token_free(tok);
	return (last);
}

int	parse_literals(t_token **tok)
{
	t_token	*last;

	last = parse_literal(tok);
	if (!last)
		return (0);
	while (last->type == TOK_UNPROCESSED && last != *tok)
	{
		if (last->prev)
			tok = &(last->prev->next);
		else
			tok = &last;
		last = parse_literal(tok);
		if (!last)
			return (0);
	}
	return (1);
}
