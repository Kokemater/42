#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *next_line;

	fd = open("text.txt", O_RDONLY);
	int i = 0;
	while ((next_line = get_next_line(fd)) != 0)
	{
		printf("[line %d] = '%s' \n", ++i, next_line);
		free(next_line);
	}
	close(fd);
}