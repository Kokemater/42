#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int total_len = len1 + len2;
	char *ret = malloc(total_len + 1);
	ret[total_len] = 0;
	if (!ret)
		return 0;
	ret[total_len] = 0;
	for (int i = 0; i < len1; i++)
		ret[i] = s1[i];
	for (int i = 0; i < len2; i++)
		ret[len1 + i] = s2[i];
	free(s1);
	return (ret);
}

char *ft_strchr(char*s, char target)
{
	for (int i=0; s[i]; i++)
	{
		if (s[i] == target)
			return s + i;
	}
	return (0);
}
/*
int main(void)
{
	char s1[] = "";
	char s2[] = "asdazf";
	printf("%d-\n",ft_strchr(s2, 'z'));
}*/