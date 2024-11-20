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

static char	*read_until_n(char *big_buff, int fd, int *end)
{
	int bytes_read;
	char tmp_buff[BUFFER_SIZE + 1];
	char	*big_buff_tmp;

	if (!big_buff)
		big_buff = calloc(1,1);
	while (!ft_strchr(big_buff, '\n'))
	{
		bytes_read = read(fd, tmp_buff, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			*end = 1;
			return (big_buff);
		}
		tmp_buff[bytes_read] = 0;
		big_buff_tmp = ft_strjoin(big_buff, tmp_buff);
		free(big_buff);
		big_buff = big_buff_tmp;
		if (!big_buff)
			return ( NULL);
	}
	return (big_buff);
	
}

static char	*extract_line(char **big_buff)
{
	int		n_position;
	char	*line;
	char	*big_buff_cpy;
	char	*n;

	n = ft_strchr(*big_buff, '\n');
	n_position = (int) (n - *big_buff);
	line = ft_strndup(*big_buff, n_position + 1);
	if (!line)
		return (NULL);
	big_buff_cpy = ft_strdup(*big_buff);
	if (!big_buff_cpy)
		return (free(line), NULL);
	free(*big_buff);
	*big_buff = ft_strdup(big_buff_cpy + n_position + 1);
	if (!(*big_buff))
		return (free(big_buff_cpy), free(line), NULL);
	return (free(big_buff_cpy), line);

}

char	*get_next_line(int fd)
{
	static char *big_buff;
	static int	end;
	char	*ans;

	if (end)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	big_buff = read_until_n(big_buff, fd, &end);
	if (!big_buff)
		return (NULL);
	if (end)
		return (big_buff);
	ans = extract_line(&big_buff);
	if (!ans)
		return (NULL);
	return (ans);
}
