#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *next_line;
	int count;

	printf("holay\n");
	count = 0;
	fd = open("texto.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s", next_line);
}