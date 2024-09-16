/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:07:13 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/23 19:07:15 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define MAX_IN_TIME 2000000

char	**create_arr(char *text);
void	print_array(char **arr, int *dim);
int		*dimensions(char *text);
char	*txt_to_string(char *filename);
int		find_min(int *arr, int size);
int		*find_biggest_square(char **arr, int *dim, char *data);
void	put_answer(char **arr, int *ans, char data);
char	*data_of_the_arr(char *text);
int		skip_the_first_line(char *text);
char	*print_error(void);
char	*stdin_to_string(void);
int		**find_obstacles(char **arr, int *dim, char obs_letter);
int		is_free(char **array, int i, int j, char free);
int		is_obstacle(char **array, int i, int j, char obstacle);
int		num_of_obstacles(char **arr, int *dim, char obs_letter);
int		dist_to_wall(int i, int j, int *dim);
int		dist_to_obstacle(char **arr, int *dim, int *pos_free, char *data);
void	set_obs_value(int **obs, int *o_i, int *pos, int *obs_values);
void	ft_strncpy(char *dest, char *src, int n);
int    check_errors(char *text);


#endif
