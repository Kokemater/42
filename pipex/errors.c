/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:28:52 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/05 10:22:21 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_argc(int argc)
{
	if (argc != 5)
	{
		ft_putendl_fd("Usage: <infile> <command1> <command2> <outfile>", 2);
		exit(1);
	}
}

static void	check_in_out(int io[2], char *argv[])
{
	io[0] = open(argv[1], O_RDONLY);
	if (io[0] < 0)
	{
		perror(argv[1]);
		exit(1);
	}
}

static void	check_pipefd(int pipefd[2])
{
	if (pipe(pipefd) != 0)
	{
		perror("pipe");
		exit(1);
	}
}

void	check_errors(int argc, char *argv[], int io[2], int pipefd[2])
{
	check_argc(argc);
	check_in_out(io, argv);
	check_pipefd(pipefd);
}

char	*prepare_command(char *command[], char *path[])
{
	char	*pname;

	pname = exec_path_finder(path, command[0]);
	if (!pname)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(command[0], 2);
		free_all(command);
		free_all(path);
		exit(127);
	}
	return (pname);
}
