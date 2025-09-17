/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 21:29:14 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/14 15:06:45 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_var_name(char *var)
{
	if (!(*var))
		return (0);
	if (!ft_isalpha(*var) && *var != '_')
		return (0);
	while (*var)
	{
		if (!ft_isalnum(*var) && *var != '_')
			return (0);
		++var;
	}
	return (1);
}

static int	replace_var(char **it, t_minishell *ms)
{
	char	*rep;

	if ((*it)[0] != '$')
		return (1);
	else if ((*it)[1] != 0 && check_var_name((*it) + 1))
	{
		rep = var_from_env((*it) + 1, ms->env);
		if (!rep)
			rep = ft_strdup("");
		if (!rep)
			return (0);
		free(*it);
		*it = rep;
	}
	else if ((*it)[1] == '?')
	{
		free(*it);
		*it = ft_itoa(ms->excode);
	}
	return (1);
}

char	*replace_vars(char *str, t_minishell *ms)
{
	char	**splits;
	char	**it;
	char	*ret;

	if (!str)
		return (0);
	splits = var_split(str);
	if (!splits)
		return (0);
	it = splits;
	if (*str != '$')
		++it;
	while (*it)
	{
		if (!replace_var(it, ms))
			return (0);
		++it;
	}
	ret = tab_join(splits);
	if (!ret)
		return (0);
	tab_free(splits);
	return (ret);
}

int	parse_vars(t_token **tok, t_minishell *ms)
{
	t_token	*it;
	char	*rep;

	it = *tok;
	while (it)
	{
		if ((it->type == TOK_UNPROCESSED || it->type == TOK_INTLITERAL)
			&& ft_strchr(it->content, '$'))
		{
			rep = replace_vars(it->content, ms);
			if (!rep)
				return (0);
			free(it->content);
			it->content = rep;
		}
		it = it->next;
	}
	return (1);
}
