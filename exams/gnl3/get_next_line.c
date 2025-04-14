#include "get_next_line.h"

char *read_until_n(int fd, char *big_buff)
{
	char *tmp_buff = malloc(BUFFER_SIZE + 1);
	if (!tmp_buff)
		return NULL;
	ssize_t bytes_readed = read(fd, tmp_buff, BUFFER_SIZE);
	while (bytes_readed > 0)
	{
		tmp_buff[bytes_readed] = 0;
		big_buff = ft_strjoin(big_buff, tmp_buff);
		if (ft_strchr(big_buff, '\n'))
			return (free(tmp_buff), big_buff);
		bytes_readed = read(fd, tmp_buff, BUFFER_SIZE);
	}
	free(tmp_buff);
	return (big_buff);
}

char *extract_line(char **big_buff)
{
	char *n_position = ft_strchr(*big_buff, '\n');
	char *line;
	char *new_big_buff;

	if (n_position)
	{
		new_big_buff = ft_strdup(n_position +1);
		line = ft_strndup(*big_buff, n_position - *big_buff +1);
	}
	else
	{
		new_big_buff = NULL;
		line = ft_strdup(*big_buff);
	}
	free(*big_buff);
	*big_buff = new_big_buff;
	return (line);
}

char *get_next_line(int fd)
{
	static char *big_buff = NULL;

	if (big_buff == NULL)
	{
		big_buff = malloc(1);
		if (!big_buff)
			return NULL;
		big_buff[0] = 0;
	}
	big_buff = read_until_n(fd, big_buff);
	if (!big_buff)
		return (free(big_buff),big_buff = NULL, NULL);
	if (!big_buff[0])
		return (free(big_buff), big_buff = NULL, NULL);
	char *line = extract_line(&big_buff);
	return (line);
}

#include <fcntl.h>
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 10; i++)
	{
		char *line = get_next_line(fd);
		printf(">>%s|\n", line);
		free(line);
	}
}