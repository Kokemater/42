/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:23:12 by jbutragu          #+#    #+#             */
/*   Updated: 2024/12/26 13:48:37 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif
#include <unistd.h>
#include <stdlib.h>
# include <stddef.h>

size_t  ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *src, int n);
char	*ft_strdup(const char *src);
char	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
#endif