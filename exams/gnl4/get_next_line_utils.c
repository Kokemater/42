#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	char *ret = malloc(sizeof(char) * (len1 + len2 + 1));
	ret[len1 + len2] = 0;
	int i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	i = 0;
	while(s2[i])
	{
		ret[len1 + i] = s2[i];
		i++;
	}
	free(s1);
	return (ret);
}

char *ft_strdup(char *s)
{
	int n = ft_strlen(s);
	char *ret = malloc(sizeof(char) * (n + 1));
	ret[n] = 0;
	for(int i = 0; s[i]; i++)
	{
		ret[i] = s[i];
	}
	return (ret);
}

char *ft_strndup(char *s, int n)
{
	char *ret = malloc(sizeof(char) * (n + 1));
	ret[n] = 0;
	for(int i = 0; s[i] && i < n; i++)
	{
		ret[i] = s[i];
	}
	return (ret);
}

char *ft_strchr(char*s , char c)
{
	while(*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}

/*
int main(void)
{
	printf("%s", ft_strjoin("hola", "pepe"));
	printf("%s", ft_strchr("ho\nla", '\n'));
}*/