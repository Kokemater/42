#include "get_next_line.h"

char *read_until_n(char *big_buff, int fd)
{
	char *tmp_buff = (char *) malloc(sizeof(char) * BUFFER_SIZE +1);
	if (!tmp_buff)
		return (NULL);
	ssize_t bytes_readed;
	bytes_readed = read(fd, tmp_buff, BUFFER_SIZE);
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
	char *nposition = ft_strchr(*big_buff, '\n');
	char *line;
	char *new_big_buff;

	if (nposition)
	{
		line = ft_strndup(*big_buff, nposition - *big_buff + 1);
		new_big_buff = ft_strdup(nposition + 1);
	}
	else
	{
		line = ft_strdup(*big_buff);
		new_big_buff = NULL;
	}
	free(*big_buff);
	*big_buff = new_big_buff;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*big_buff = NULL;

	if (!big_buff)
	{
		big_buff = (char *)malloc(1);
		if (!big_buff)
			return (NULL);
		big_buff[0] = 0;
	}
	big_buff = read_until_n(big_buff, fd);
	if (!big_buff)
		return (free(big_buff), big_buff = NULL, NULL);
	if (!(*big_buff))
		return (free(big_buff), big_buff = NULL, NULL);
	char *line = extract_line(&big_buff);
	return (line);
}


int main(void)
{
	int fd = open("test", O_RDONLY);
	char *line;
	for (int i = 0; i < 10; i++)
	{
		line = get_next_line(fd);
		printf("%s|\n", line);
		free(line);
	}
}