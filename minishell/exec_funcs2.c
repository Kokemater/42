/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:31:28 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/14 14:56:48 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin_or_external(t_cmd *cmd, t_minishell *ms)
{
	char	*path;
	int		ret;

	ret = builtins_nofork(cmd, ms);
	if (ret == 0)
		minishell_exit(ms, cmd->excode);
	else if (ret == 1)
		return ;
	else if (ft_strcmp(cmd->args[0], "env") == 0)
		minishell_exit(ms, env_main(ms->env));
	else if (ft_strcmp(cmd->args[0], "echo") == 0)
		minishell_exit(ms, echo_main(cmd->args));
	else if (ft_strcmp(cmd->args[0], "pwd") == 0)
		minishell_exit(ms, pwd_main());
	else
	{
		path = find_exec_path(cmd->args[0], ms);
		if (!path)
			return ;
		free(cmd->args[0]);
		cmd->args[0] = path;
		execve(cmd->args[0], cmd->args, ms->env);
		minishell_exit(ms, 1);
	}
}

int	handle_parent_pipe_management(int *prev_fd, int pipe_fd[2])
{
	if (pipe_fd[1] > 2)
		close(pipe_fd[1]);
	if (*prev_fd != -1)
		close(*prev_fd);
	*prev_fd = pipe_fd[0];
	return (0);
}

int	builtin_alone(t_cmd *cmd, t_minishell *ms)
{
	int	ret;

	if (!ms->cmd->next)
	{
		ret = builtins_nofork(cmd, ms);
		if (ret < 2)
			return (ret);
	}
	return (-1);
}
