/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:13:43 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/15 13:46:46 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

extern int	g_sigstatus;

static char	*free_swap(char *s, char *f)
{
	if (f)
		free(f);
	return (s);
}

static char	*process_heredoc_line(char *res, char **line)
{
	if (res)
		res = free_swap(ft_strjoin(res, *line), res);
	else
		res = ft_strdup(*line);
	free(*line);
	if (!res)
		return (0);
	ft_putstr_fd("> ", 1);
	*line = get_next_line(0);
	return (res);
}

char	*heredoc_read(char *del)
{
	char	*line;
	char	*res;

	signal(SIGINT, sigint_heredoc);
	ft_putstr_fd("> ", 1);
	line = get_next_line(0);
	res = 0;
	while (line)
	{
		if (g_sigstatus == SIGINT)
		{
			if (res)
				free(res);
			return (signal(SIGINT, sigint_idle), free(line), (char *)0);
		}
		if (ft_strncmp(line, del, ft_strlen(line) - 1) == 0)
			break ;
		res = process_heredoc_line(res, &line);
	}
	if (line)
		free(line);
	signal(SIGINT, sigint_idle);
	return (res);
}

int	heredoc_pipe(char *heredoc)
{
	int	p[2];

	if (pipe(p) != 0)
	{
		err_str("heredoc pipe failed\n");
		return (-1);
	}
	if (heredoc)
		write(p[1], heredoc, ft_strlen(heredoc));
	close(p[1]);
	return (p[0]);
}
