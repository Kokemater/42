/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:05:11 by dmoraled          #+#    #+#             */
/*   Updated: 2025/06/24 01:30:37 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_separator(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_isspace(*str))
			return (str);
		++str;
	}
	return (0);
}

static t_token	*parse_separator_rest(t_token *last, char *s)
{
	last = token_insert(token_new(0, 0, TOK_SEPARATOR), &last);
	if (!last)
		return (0);
	while (ft_isspace(*s))
		++s;
	if (*s)
		last = token_insert(token_new(s, ft_strlen(s), TOK_UNPROCESSED), &last);
	return (last);
}

static t_token	*parse_separator(t_token **tok)
{
	char	*line;
	t_token	*last;
	char	*s;

	line = (*tok)->content;
	last = *tok;
	if (last->type != TOK_UNPROCESSED)
		return (last);
	s = find_separator(line);
	if (!s)
		return (last);
	if (s > line)
		last = token_insert(token_new(line, s - line, TOK_UNPROCESSED), &last);
	if (!last)
		return (0);
	last = parse_separator_rest(last, s);
	token_free(tok);
	return (last);
}

int	parse_separators(t_token **tok)
{
	t_token	*last;

	last = parse_separator(tok);
	if (!last)
		return (0);
	while (last)
	{
		if (last->type == TOK_UNPROCESSED && find_separator(last->content))
		{
			if (last->prev)
				tok = &last->prev->next;
			else
				tok = &last;
			last = parse_separator(tok);
			if (!last)
				return (0);
			continue ;
		}
		last = last->next;
	}
	return (1);
}
