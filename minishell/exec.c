/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:37:14 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/15 14:34:22 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_sigstatus;

static void	print_on_signal(int laststat)
{
	if (WIFSIGNALED(laststat))
	{
		if (WTERMSIG(laststat) == SIGINT)
			ft_putendl_fd("", 1);
		else if (WTERMSIG(laststat) == SIGQUIT)
			ft_putendl_fd("Quit (core dumped)", 1);
	}
}

static int	get_exit_code(t_cmd *lastcmd)
{
	int	laststat;
	int	ret;
	int	pid;

	ret = 0;
	if (!lastcmd)
		return (0);
	if (lastcmd->excode != 0)
		ret = lastcmd->excode;
	pid = waitpid(-1, &laststat, 0);
	while (pid != -1)
	{
		print_on_signal(laststat);
		if (pid == lastcmd->pid)
		{
			if (WIFEXITED(laststat))
				ret = WEXITSTATUS(laststat);
			else if (WIFSIGNALED(laststat))
				ret = 128 + WTERMSIG(laststat);
		}
		pid = waitpid(-1, &laststat, 0);
	}
	return (ret);
}

static int	cmd_exec_single(t_cmd *cmd, int *prev_fd, t_minishell *ms)
{
	int		pipe_fd[2];
	int		ret;

	pipe_fd[0] = 0;
	pipe_fd[1] = 0;
	ret = builtin_alone(cmd, ms);
	if (ret != -1)
		return (ret);
	if (!create_pipe(cmd, pipe_fd, &cmd->pid))
		return (1);
	else if (cmd->args && cmd->pid == 0)
	{
		redirect_pipe(prev_fd, cmd, pipe_fd);
		redirect_custom(cmd);
		if (cmd->excode != 0)
			return (ms->exit = 1, ms->excode = cmd->excode, 0);
		execute_builtin_or_external(cmd, ms);
	}
	if (cmd->pid != 0)
		handle_parent_pipe_management(prev_fd, pipe_fd);
	return (0);
}

int	cmd_exec(t_minishell *ms)
{
	t_cmd	*cmd;
	int		prev_fd;
	int		r;

	cmd = ms->cmd;
	prev_fd = -1;
	if (g_sigstatus == SIGINT)
		return (g_sigstatus = 0, ms->excode = 130, 0);
	signal(SIGINT, sigint_exec);
	signal(SIGQUIT, SIG_DFL);
	while (cmd)
	{
		r = cmd_exec_single(cmd, &prev_fd, ms);
		if (ms->exit || r == 1)
			return (1);
		cmd = cmd->next;
	}
	signal(SIGQUIT, SIG_IGN);
	ms->excode = get_exit_code(cmd_last(ms->cmd));
	signal(SIGINT, sigint_idle);
	g_sigstatus = 0;
	return (0);
}
