#include "get_next_line.h"
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