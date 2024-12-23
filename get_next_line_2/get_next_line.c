#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	int		n;
	char	*dest;
	int		i;

	i = 0;
	n = ft_strlen(src);

	dest = (char *) malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	dest[n] = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

static char	*read_until_n(int fd, char *big_buff)
{
	char	*tmp_buff;
	char	*new_buff;
	ssize_t	n_chars_readed;

	tmp_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buff)
		return (free(big_buff), NULL);
	n_chars_readed = read(fd, tmp_buff, BUFFER_SIZE);
	while (n_chars_readed > 0)
	{
		tmp_buff[n_chars_readed] = '\0';
		new_buff = ft_strjoin(big_buff, tmp_buff);
		if (!new_buff)
			return (free(big_buff), free(tmp_buff), NULL);
		free(big_buff);
		big_buff = new_buff;
		if (ft_strchr(big_buff, '\n'))
			break ;
		n_chars_readed = read(fd, tmp_buff, BUFFER_SIZE);
	}
	free(tmp_buff);
	if (n_chars_readed < 0)
		return (free(big_buff), NULL);
	return (big_buff);
}

static char	*extract_line(char **big_buff)
{
	char	*line;
	char	*new_buff;
	char	*newline_pos;

	newline_pos = ft_strchr(*big_buff, '\n');
	if (newline_pos) 
	{
		line = ft_strndup(*big_buff, newline_pos - *big_buff + 1);
		if (!line)
			return (NULL);
		new_buff = ft_strdup(newline_pos + 1);
		if (!new_buff)
			return (free(line), NULL);
	}
	else
	{
		line = ft_strdup(*big_buff);
		if (!line)
			return (NULL);
		new_buff = NULL;
	}
	free(*big_buff);
	*big_buff = new_buff;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*big_buff = NULL;

	if (fd < 0)
		return (NULL);
	if (!big_buff)
	{
		big_buff = ft_calloc(1, 1);
		if (!big_buff)
			return (NULL);
	}
	big_buff = read_until_n(fd, big_buff);
	if (!big_buff)
		return (NULL);
	if (*big_buff == '\0')
		return (free(big_buff),big_buff = NULL, NULL);
	return (extract_line(&big_buff));
}
