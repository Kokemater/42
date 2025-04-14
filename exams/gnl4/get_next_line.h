#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int ft_strlen(char *s);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(char*s , char c);
char *ft_strdup(char *s);
char *ft_strndup(char *s, int n);

#endif