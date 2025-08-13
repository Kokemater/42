#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}


int    picoshell(char **cmds[])
{
	int fd[2];
	int i = 0;
	int in_fd = 0;
	int status = 0;
	pid_t pid;
	while (cmds[i] && ft_strlen(cmds[i][0])>0)
	{
		if (cmds[i+1] && ft_strlen(cmds[i+1][0])>0)
			pipe(fd);
		else
		{
			fd[0] = -1;
			fd[1] = -1;
		}
		pid = fork();
		if (pid == -1)
		{
			if (fd[0] == -1)
				close(fd[0]);
			if (fd[1] == -1)
				close(fd[1]);
			if (in_fd != 0)
				close(in_fd);
		}
		if (pid == 0)
		{
			dup2(in_fd, 0);
			if (cmds[i+1] && ft_strlen(cmds[i+1][0])>0)
				dup2(fd[1],1);
			if (fd[0] != -1)
				close(fd[0]);
			if (fd[1] != -1)
				close(fd[1]);
			if (in_fd != 0)
				close(in_fd);
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		else
		{
			if (fd[1] != -1)
				close(fd[1]);
			in_fd = fd[0];
			i++;
		}

	}
	while(wait(&status) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status))
			return (1);
		if (!WIFEXITED(status))
			return (1);
	}
	return (0);
}

int main(void)
{
	char *cmd1[] = {"ls", "-l", NULL};
	char *cmd2[] = {"cat", "-e", NULL};
	char *cmd3[] = {"grep", "a.out", NULL};
	char *last[] = {""};
	char **cmds[] = {cmd1, cmd2, cmd3, last};
	return (picoshell(cmds));
}
