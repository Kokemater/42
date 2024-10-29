#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (str[i] != 0)
        {
                i++;
        }
        return (i);
}
static void    *ft_memset(void *ptr, int val, size_t num)
{
        size_t                  i;

        i = 0;
        while (i < num)
        {
                ((unsigned char *) ptr)[i] = val;
                i++;
        }
        return (ptr);
}

static void    *ft_calloc(size_t nmemb, size_t size)
{
        void    *new;

        new = (char *) malloc(nmemb * size);
        if (!new)
                return (NULL);
        ft_memset(new, 0, nmemb * size);
        return (new);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        int             total_space;
        char    *result;
        int             i;
        int             j;

        i = 0;
        j = 0;
        total_space = ft_strlen(s1) + ft_strlen(s2);
        result = (char *) malloc(sizeof(char) * total_space + 1);
        if (!result)
                return (NULL);
        while (s1[i] != 0)
        {
                result[i] = s1[i];
                i++;
        }
        while (s2[j] != 0)
        {
                result[i] = s2[j];
                i++;
                j++;
        }
        result[i] = 0;
        return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if ((char) c == s[i])
		return ((char *)(s + i));
	return (0);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *buff;

	buffer = (char *) ft_calloc(1,sizeof(char));
	buff = (char *) ft_calloc(BYTES_READ + 1, sizeof(char));
	while(ft_strchr(buffer, '\n'))
	{
		read(fd, buff, BYTES_READ);
		buffer = ft_strjoin(buffer, buff);
	}
	return (buffer);
}
