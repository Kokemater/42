#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int    ft_popen(const char *file, char * const argv[], char type)
{
	int fd[2];
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(fd) == -1)
		return -1;

	pid_t pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}

	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			dup2(fd[1], 1);
		}
		if (type == 'w')
		{
			close(fd[1]);
			dup2(fd[0], 0);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(-1);
	}
	else
	{
		if (type == 'r')
		{
			close(fd[1]);
			return fd[0];
		}
		if (type == 'w')
		{
			close(fd[0]);
			return fd[1];
		}
	}
	return 0;
}


#include <stdio.h>

int main() {
    // Queremos ejecutar: ls -l
    char *args[] = {"ls", "-l", NULL};
	char file[] = "ls";
    int fd = ft_popen(file, args, 'r');
    if (fd == -1) {
        perror("ft_popen");
        return 1;
    }

    FILE *fp = fdopen(fd, "r"); // Convertimos fd a FILE*
    if (!fp) {
        perror("fdopen");
        close(fd);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("OUTPUT: %s", buffer);
    }

    fclose(fp); 

	char *const args2[] = {"sort", NULL};
	const char file2[] = "sort";

    int fd2 = ft_popen(file2, args2, 'w');
    if (fd2 == -1) {
        perror("ft_popen");
        return 1;
    }

    FILE *fp2 = fdopen(fd2, "w");
    if (!fp) {
        perror("fdopen");
        close(fd2);
        return 1;
    }

    // Enviamos texto desordenado a sort
    fprintf(fp2, "banana\n");
    fprintf(fp2, "apple\n");
    fprintf(fp2, "orange\n");
    fprintf(fp2, "grape\n");

    fclose(fp2); // Cierra el pipe y envía EOF al proceso hijo
    
    return 0;
}
