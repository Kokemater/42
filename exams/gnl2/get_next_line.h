#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strchr(char *s, char target);
int ft_strlen(char *s);
char *ft_strjoin(char *s1, char *s2);
char *ft_strndup(char *s, int n);
char *ft_strdup(char *s);

#endif