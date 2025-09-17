/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:40:38 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/12 13:31:53 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_insert(t_token *new, t_token **to)
{
	t_token	*next;

	if (!new || !to)
		return (0);
	if (!(*to))
	{
		*to = new;
		return (new);
	}
	next = (*to)->next;
	(*to)->next = new;
	new->next = next;
	if (new->next)
		new->next->prev = new;
	new->prev = *to;
	return (new);
}

void	token_free(t_token **tok)
{
	t_token	*t;
	t_token	*p;

	if (!tok || !(*tok))
		return ;
	t = *tok;
	if (t->next)
		t->next->prev = 0;
	p = (*tok)->prev;
	*tok = (*tok)->next;
	if (*tok)
		(*tok)->prev = p;
	if (t->content)
		free(t->content);
	free(t);
}

t_token	*token_new(char *content, int len, int type)
{
	t_token	*ret;

	ret = malloc(sizeof(t_token));
	if (!ret)
		return (0);
	ret->type = type;
	ret->content = ft_substr(content, 0, len);
	if (!ret->content && content)
	{
		free(ret);
		return (0);
	}
	ret->next = 0;
	ret->prev = 0;
	return (ret);
}

void	token_print(t_token *tok)
{
	while (tok)
	{
		ft_printf("[%i] {%s}\n", tok->type, tok->content);
		tok = tok->next;
	}
}
