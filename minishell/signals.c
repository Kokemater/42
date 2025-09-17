/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:16:49 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/15 13:47:45 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

int	g_sigstatus = SIGS_DEFAULT;

void	sigint_handler(int sig)
{
	(void)sig;
	if (g_sigstatus == SIGS_DEFAULT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (g_sigstatus == SIGS_HEREDOC)
	{
		g_sigstatus = SIGS_INT;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}

void	sigint_exec(int sig)
{
	(void)sig;
}

void	sigint_heredoc(int sig)
{
	(void)sig;
	g_sigstatus = SIGINT;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	sigint_idle(int sig)
{
	(void)sig;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
