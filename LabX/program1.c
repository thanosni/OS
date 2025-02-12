#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	int i;

	for (i = 0; i < 3; i++) {
		pid = fork();

		if (pid == 0) {
			printf("I am child process %d with PID : %d\n", i+1, getpid());
			sleep(1);
			exit(0);
		}
		else if (pid < 0) {
			perror("fork failed\n");
			exit(1);
		}
	}
	for (i = 0; i < 3; i++) {
		wait(NULL);
	}

	printf("Parent PID : %d\n", getpid());

	return 0;
}
