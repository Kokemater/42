/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:56:24 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/10 11:51:26 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_redir(char *str)
{
	while (*str)
	{
		if (*str == '<' || *str == '>')
			return (1);
		++str;
	}
	return (0);
}

static char	redir_type(char redir, char next)
{
	if (redir == '<')
	{
		if (next == '<')
			return (TOK_REDIR_HEREDOC);
		return (TOK_REDIR_IN);
	}
	else if (redir == '>')
	{
		if (next == '>')
			return (TOK_REDIR_APPEND);
		return (TOK_REDIR_OUT);
	}
	return (TOK_UNPROCESSED);
}

static t_token	*append_rest(t_token *last, char *s)
{
	++s;
	if (*s == *(s - 1))
		++s;
	if (*s)
		last = token_insert(token_new(s, ft_strlen(s), TOK_UNPROCESSED),
				&last);
	return (last);
}

static t_token	*parse_redir(t_token **tok)
{
	char	*line;
	t_token	*last;
	char	*s;

	line = (*tok)->content;
	last = *tok;
	if (last->type != TOK_UNPROCESSED)
		return (last);
	s = ft_earlier(ft_strchr(line, '<'), ft_strchr(line, '>'));
	if (!s)
		return (last);
	if (s > line)
		last = token_insert(token_new(line, s - line, TOK_UNPROCESSED), &last);
	if (!last)
		return (0);
	last = token_insert(token_new(0, 0, redir_type(*s, *(s + 1))), &last);
	if (!last)
		return (0);
	last = append_rest(last, s);
	if (!last)
		return (0);
	token_free(tok);
	return (last);
}

int	parse_redirs(t_token **tok)
{
	t_token	*last;

	last = parse_redir(tok);
	if (!last)
		return (0);
	while (last)
	{
		if (last->type == TOK_UNPROCESSED && has_redir(last->content))
		{
			if (last->prev)
				tok = &last->prev->next;
			else
				tok = &last;
			last = parse_redir(tok);
			if (!last)
				return (0);
			continue ;
		}
		last = last->next;
	}
	return (1);
}
