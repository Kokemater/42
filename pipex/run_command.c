/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:30:16 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/05 00:58:31 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	run(char *command[], char *path[], char *env[], int io[3])
{
	pid_t	pid;
	char	*pname;

	if (!command || !(*command))
	{
		free_all(command);
		return (0);
	}
	pid = fork();
	if (pid != 0)
	{
		free_all(command);
		return (pid);
	}
	dup2(io[0], 0);
	dup2(io[1], 1);
	close(io[2]);
	pname = prepare_command(command, path);
	free(command[0]);
	command[0] = pname;
	execve(command[0], command, env);
	return (pid);
}
