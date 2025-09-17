/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:30:09 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/14 13:27:50 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins_nofork(t_cmd *cmd, t_minishell *ms)
{
	if (!cmd->args)
		return (2);
	if (ft_strcmp(cmd->args[0], "exit") == 0)
	{
		minishell_exit(ms, exit_main(cmd->args));
		return (1);
	}
	else if (ft_strcmp(cmd->args[0], "export") == 0)
	{
		cmd->excode = export_main(cmd->args, ms);
		return (0);
	}
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
	{
		cmd->excode = unset_main(cmd->args, ms);
		return (0);
	}
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
	{
		cmd->excode = cd_main(cmd->args, ms);
		return (0);
	}
	return (2);
}

int	create_pipe(t_cmd *cmd, int pipe_fd[2], int *pid)
{
	if (cmd->next && pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (0);
	}
	*pid = fork();
	if (*pid < 0)
	{
		perror("fork");
		return (0);
	}
	if (*pid == 0 && !cmd->args)
		exit(0);
	return (1);
}

void	redirect_pipe(int *prev_fd, t_cmd *cmd, int pipe_fd[2])
{
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, STDIN_FILENO);
		close(*prev_fd);
	}
	if (cmd->next)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
}

void	redirect_custom(t_cmd *cmd)
{
	if (cmd->in != STDIN_FILENO)
	{
		dup2(cmd->in, STDIN_FILENO);
		close(cmd->in);
	}
	if (cmd->out != STDOUT_FILENO)
	{
		dup2(cmd->out, STDOUT_FILENO);
		close(cmd->out);
	}
}
