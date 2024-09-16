#include <stdlib.h>
#include <stdio.h>


int	num_chars(char *word)
{
	int	i;

	i = 0;
	while (word[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	last_index;

	last_index = num_chars(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[last_index + i] = src[i];
		i++;
	}
	dest[last_index + i] = '\0';
	return (dest);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i;
    int max_chars;
    char *word;

    i = 0;
    max_chars = num_chars(sep) * (size - 1);
    while(i < size)
        max_chars += num_chars(strs[i++]);
    i = 0;
    word = malloc(sizeof(char) * max_chars + 1);
    if (!word)
        return (0);
    while(i <= (int) sizeof(char) * max_chars + 1)
        word[i++] = 0;
    i = 0;
    while(i < size)
    {
        ft_strcat(word, strs[i]);
        if (i < size -1)
            ft_strcat(word, sep);
        i++;
    }
    return (word);
}
/*
int main(void)
{
    char texto1[] = "hola";
    char texto2[] = "ados";
    char texto3[] = "chao";
    char** big = malloc(sizeof(char *) * 3 + 1);
    *big = texto1;
    *(big + 1) = texto2;
    *(big + 2) = texto3;
    char sep[] = "Hola";
    char *word = ft_strjoin(3, big, sep);
    printf("%s",word);
}
*/