#ifndef RUSH_H
# define RUSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define N 1000
# define DICT_SIZE 41
# define DICT_FILE "numbers.dict"
# define TRUE 1
# define FALSE 0
# define ALL 40

typedef struct num_node
{
        char    *key;
        char    *value;
}       num_node;

void	print_error(void);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*dict_to_string(const char *dict);
num_node	**create_array_of_structs(const char *dict);
char	*check_into_dict(char *num, int n);
char *check_into_dict(char *num, int n);
void	print_error(void);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	print_error(void);
int		atoi_english(char *str);
int		input_dict(char *key, char *value);
void	print_hundred();

#endif