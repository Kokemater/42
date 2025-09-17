/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:34:10 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/12 13:33:54 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	err_open_literal(char literal)
{
	ft_putstr_fd("error: ", 2);
	ft_putchar_fd(literal, 2);
	ft_putstr_fd(" not closed\n", 2);
}

void	err_str(char *str)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(str, 2);
}

void	err_str2(char *s1, char *s2, int error)
{
	if (error)
		ft_putstr_fd("error: ", 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
}

int	check_pipe_syntax(t_token **tok)
{
	t_token	*last;
	int		last_pipe;

	last = *tok;
	while (last && last->type == TOK_SEPARATOR)
		last = last->next;
	if (last && last->type == TOK_PIPE)
		return (0);
	last_pipe = 0;
	while (last)
	{
		if (last->type == TOK_PIPE)
		{
			if (last_pipe == 1)
				return (0);
			last_pipe = 1;
		}
		else if (last->type != TOK_SEPARATOR)
			last_pipe = 0;
		last = last->next;
	}
	if (last_pipe)
		return (0);
	return (1);
}

int	check_next_literal(t_token **tok)
{
	t_token	*t;

	t = *tok;
	t = next_literal(t);
	if (!t)
	{
		ft_putstr_fd("syntax error: expected literal\n", 2);
		*tok = 0;
		return (0);
	}
	*tok = t;
	return (1);
}
