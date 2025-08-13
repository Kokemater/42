#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int    ft_popen(const char *file, char * const argv[], char type)
{
	if (type != 'r' && type != 'w')
		return (-1);
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	if (pid == -1)
	{
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
			dup2(fd[1], 1);
		else
			dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(0);
	}
	else
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	else
	{
		close(fd[0]);
		return (fd[1]);
	}
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
