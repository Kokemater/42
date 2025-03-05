/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:55:14 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/05 10:40:16 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	int		in_out[2];
	int		pipe_fd[2];
	pid_t	pids[2];
	char	**path;
	int		return_val;

	check_errors(argc, argv, in_out, pipe_fd);
	path = get_path(env);
	pids[0] = run(ft_split(argv[2], ' '), path, env,
			(int [3]){in_out[0], pipe_fd[1], pipe_fd[0]});
	in_out[1] = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (in_out[1] < 0)
	{
		in_out[1] = open(argv[4], O_WRONLY);
		if (in_out[1] < 0)
			perror(argv[4]);
	}
	pids[1] = run(ft_split(argv[3], ' '), path, env,
			(int [3]){pipe_fd[0], in_out[1], pipe_fd[1]});
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pids[0], 0, 0);
	waitpid(pids[1], &return_val, 0);
	free_all(path);
	return (return_value(return_val, in_out));
}
