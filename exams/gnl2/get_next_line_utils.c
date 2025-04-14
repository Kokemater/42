#include "get_next_line.h"

char *ft_strchr(char *s, char target)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == target)
			return s + i;
		i++;
	}
	return 0;
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

char *ft_strjoin(char *s1, char *s2)
{
	int s1_len = ft_strlen(s1);
	int s2_len = ft_strlen(s2);
	int total_len = s1_len + s2_len;
	char *ret = malloc(total_len + 1);
	ret[total_len] = 0;

	for (int i = 0; i < s1_len; i++)
		ret[i] = s1[i];
	for (int i = 0; i < s2_len; i++)
		ret[s1_len + i] = s2[i];
	return (ret);
}

char *ft_strdup(char *s)
{
	char *ret;
	int len = ft_strlen(s);
	ret = malloc(len +1);
	ret[len] = 0;
	for (int i = 0; i < len; i++)
		ret[i] = s[i];
	return ret;
}

char *ft_strndup(char *s, int n)
{
	char *ret;
	int len = n;
	ret = malloc(len +1);
	ret[len] = 0;
	for (int i = 0; i < n; i++)
		ret[i] = s[i];
	return ret;
}

char *ft_strdup(char *s)
{
	char *ret;
	int len = ft_strlen(s);
	ret = malloc(len +1);
	ret[len] = 0;
	for (int i = 0; i < len; i++)
		ret[i] = s[i];
	return ret;
}

char *ft_strndup(char *s, int n)
{
	char *ret;
	int len = n;
	ret = malloc(len +1);
	ret[len] = 0;
	for (int i = 0; i < n; i++)
		ret[i] = s[i];
	return ret;
}

/*
int main(void)
{
	printf("%s- \n", ft_strjoin("hola", "papa"));
	printf("%s-\n", ft_strchr("ho\nla", '\n'));
	printf("%s- \n", ft_strndup("hola", 2));
}
*/

