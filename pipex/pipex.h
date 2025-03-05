/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:55:11 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/05 00:58:41 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libraries/Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

int		return_value(int last_ret, int io[2]);
char	*prepare_command(char *command[], char *path[]);
char	**get_path(char *env[]);
char	*exec_path_finder(char **path, char *name);
void	free_all(char **tab);
void	check_errors(int argc, char *argv[], int io[2], int pipefd[2]);
pid_t	run(char *command[], char *path[], char *env[], int io[3]);
#endif
