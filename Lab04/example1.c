#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t pid;

	pid = fork();

	if (pid < 0) {
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) {
		printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
		execlp("/bin/ls", "ls", "-l", NULL);
		perror("execlp failed");
		exit(EXIT_FAILURE);
	}
	else {
		printf("Parent Process: PID = %d, Created Child PID = %d\n", getpid(), pid);
		wait(NULL);
		printf("Parent Process: CHild has terminated.\n");
	}

	return 0;
}
