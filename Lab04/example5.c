#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sigusr1_handler(int sig) {
	printf("Child recieved SIGUSR1 	(signal %d).\n", sig);
}

int main() {
	pid_t pid;

	pid = fork();

	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
			perror("signal");
			exit(EXIT_FAILURE);
		}

		printf("Child process ID: %d. Waiting for SIGUSR1...\n", getpid());

		while (1) {
			pause();
		}
	} else {
		printf("Parent process Id : %d. Child PID: %d\n", getpid(), pid);

		sleep(3);

		printf("Parent sending SIGUSR1 to child.\n");
		if (kill(pid, SIGUSR1) == -1) {
			perror("kill");
			exit(EXIT_FAILURE);
		}

		sleep(1);

		printf("Parent sending SIGTERM to child.\n");
		if(kill(pid, SIGTERM) == -1) {
			perror("kill");
			exit(EXIT_FAILURE);
		}

		wait(NULL);
		printf("Child process terminated.\n");
	}

	return 0;
}

