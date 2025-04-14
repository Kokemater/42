#include "get_next_line.h"

char *read_until_n(int fd, char *big_buff)
{
	ssize_t bytes_readed;
	char *tmp_buff = malloc(BUFFER_SIZE + 1);
	tmp_buff[BUFFER_SIZE] = 0;
	bytes_readed = read(fd, tmp_buff, BUFFER_SIZE);
	while(bytes_readed)
	{
		tmp_buff[bytes_readed] = 0;
		big_buff = ft_strjoin(tmp_buff, big_buff);
		if (ft_strchr(big_buff, '\n'))
			return (free(tmp_buff), big_buff);
		bytes_readed = read(fd, tmp_buff, BUFFER_SIZE);
	}
	return (free(tmp_buff), big_buff);
}

char *extract_line(char **big_buff)
{
	char *ret;
	char *n_position = ft_strchr(*big_buff, '\n') +1;
	char *new_big_buff;
	if (n_position)
	{
		new_big_buff = ft_strdup(n_position);
		ret = ft_strndup(*big_buff, n_position - *big_buff);
	}
	else
	{
		new_big_buff = 0;
		ret = ft_strdup(*big_buff);
	}
	free(*big_buff);
	*big_buff = new_big_buff;
	return (ret);
}


char *get_next_line(int fd)
{
	static char *big_buff = NULL;

	if (fd < 0)
		return (NULL);
	if (!big_buff)
	{
		big_buff = malloc(1);
		if (!big_buff)
			return (NULL);
		big_buff[0] = 0;
	}
	big_buff = read_until_n(fd, big_buff);
	if (!big_buff)
		return (NULL);
	if (*big_buff== 0)
		return (free(big_buff),big_buff = NULL, NULL);
	//printf("big_buff: >%s-\n", big_buff);
	//printf("big_buff: >>%s-\n", big_buff);

	return (extract_line(&big_buff));
}
#include <fcntl.h>
int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int i = 0;
	char *line;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("[%d]>%s-\n", i, line);
		free(line);
		i++;
	}
}

