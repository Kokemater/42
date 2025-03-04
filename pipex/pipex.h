/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:55:11 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/04 11:52:48 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include "Libraries/Libft/libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

char	**get_path(char *env[]);
char	*find_exec_path(char **path, char *name);
void	free_tab(char **tab);

#endif
