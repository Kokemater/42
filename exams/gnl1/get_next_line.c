#include "get_next_line.h"
# include <stddef.h>


char *read_until_n(int fd, char *big_buff)
{
	char *tmp_buff;
	char *new_buff;
	ssize_t n_bytes_readed;

	tmp_buff = malloc(BUFFER_SIZE + 1);
	if (!tmp_buff)
		return (free(big_buff), NULL);

	n_bytes_readed = read(fd, tmp_buff, BUFFER_SIZE);
	while(n_bytes_readed > 0)
	{
		tmp_buff[n_bytes_readed] = 0;
		big_buff = ft_strjoin(big_buff, tmp_buff);
		if (!big_buff)
			return (free(tmp_buff), NULL);
		if (ft_strchr(big_buff, '\n'))
			return (free(tmp_buff),big_buff);
		n_bytes_readed = read(fd, tmp_buff, BUFFER_SIZE);
	}
	free(tmp_buff);
	if (n_bytes_readed > 0)
		return (free(big_buff), NULL);
	return (big_buff);
}

int find_n_position(char *big_buff)
{
	for (int i = 0; big_buff[i]; i++)
	{
		if (big_buff[i] == '\n' || big_buff[i] == 0)
			return i;
	}
	return -1;
}

char *ft_strndup(char *s, int n)
{
	char *ret = malloc(n +1);
	int i =0;

	while (i < n && s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return ret;
}

char *ft_strdup(char *s)
{
	char *ret = malloc(ft_strlen(s) +1);
	int i =0;

	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return ret;
}

char *extract_line(char **big_buff)
{
	char *ret;
	char *newline_pos;
	char *new_buff;
	newline_pos = ft_strchr(*big_buff, '\n');

	if (newline_pos)
	{
		ret = ft_strndup(*big_buff, newline_pos - *big_buff + 1);
		if (!ret)
			return (NULL);
		new_buff = ft_strdup(newline_pos + 1);
		if (!new_buff)
			return (free(ret),NULL);
	}
	else
	{
		ret = ft_strdup(*big_buff);
		if (!ret)
			return (NULL);
		new_buff = NULL;
	}
	free(*big_buff);
	*big_buff = new_buff;
	return (ret);
}

char *get_next_line(int fd)
{
	static char *big_buff = NULL;

	if (!big_buff)
	{
		big_buff = malloc(1);
		big_buff[0] = 0;
	}
	big_buff = read_until_n(fd, big_buff);
	if (!big_buff)
		return (NULL);
	if (*big_buff == 0)
		return(free(big_buff), NULL);
	char *line = extract_line(&big_buff);
	return (line);
}

#include <fcntl.h>

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int i = 0;
	char *line;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("[%d]>%s-\n", i+1, line);
		free(line);
		i++;
	}
}