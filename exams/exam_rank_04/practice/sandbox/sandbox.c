/*
Assignment name		:	sandbox
Expected files		:	sandbox.c
Allowed functions	:	fork, waitpid, exit, alarm, sigaction, kill,
						printf, strsignal, errno
===============================================================================

Write the following function:

#include <stdbool.h>
int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)

This function must test if the function f is a nice function or a bad function,
you will return 1 if f is nice , 0 if f is bad or -1 in case of an error in
your function.

A function is considered bad if it is terminated or stopped by a signal
(segfault, abort...), if it exit with any other exit code than 0 or if it
times out.

If verbose is true, you must write the appropriate message among the following:

"Nice function!\n"
"Bad function: exited with code <exit_code>\n"
"Bad function: <signal description>\n"
"Bad function: timed out after <timeout> seconds\n"

You must not leak processes (even in zombie state, this will be checked using
wait).

We will test your code with very bad functions.
*/

// sandbox.c

#include <unistd.h>     // fork(), alarm(), _exit()
#include <sys/wait.h>   // waitpid(), WIFEXITED, WIFSIGNALED, WEXITSTATUS, WTERMSIG
#include <signal.h>     // sigaction, SIGALRM, SIGKILL, struct sigaction
#include <stdbool.h>    // bool
#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <errno.h>      // errno, EINTR
#include <string.h>     // strsignal()


void do_nothin(int a)
{
	(void) a;
}
int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		alarm(timeout);
		f();
		_exit(0);
	}
	// Create handler
	struct sigaction sa;
	sa.sa_handler = do_nothin;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, NULL);
	//

	alarm(timeout);
	int status;
	int r = waitpid(pid, &status, 0);
	if (r < 0)
	{
		if (errno == EINTR)
		{
			kill(pid, SIGKILL);
			waitpid(pid, NULL,0);
			if (verbose)
				printf("Bad function: timed out after %d seconds\n", timeout);
			return (0);
		}
		return -1;
	}
	alarm(0);
	if (WIFEXITED(status))
	{
		int code = WEXITSTATUS(status);
		if (code == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return (1);
		}
		else
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", code);
			return (0);

		}
	}
	if (WIFSIGNALED(status))
	{
		int n_code = WTERMSIG(status);
		if (n_code == SIGALRM)
		{
			if (verbose)
				printf("Bad function: timed out after %d seconds\n", timeout);
		}
		else
		{
			if (verbose)
                printf("Bad function: %s\n", strsignal(n_code));
		}
		return 0;
	}
	return -1;
}

////////////////////////// TESTS //////////////////////////// (NO ENTREGAR)
void f (void)
{
	return;
}
int main(void)
{
	return (sandbox(f, 1, true));
}