#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# define BUFFER_SIZE 4
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