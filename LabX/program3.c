#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h>
#include <signal.h>
#include <sys/wait.h>

void sigusr1_handler(int sig) {
	printf("I'm the the child and I just recieved SIGUSR1 signal (%d).\nExiting...\n", sig);
	exit(EXIT_SUCCESS);
}

int main(void) {
	pid_t pid;

	pid = fork();

	if (pid == -1) {
		perror("Fork failed : \n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) {
		if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
			perror("Signal failed : \n");
			exit(EXIT_FAILURE);
		}
		
		printf("I'm the child and am waiting for signal SIGUSR1.\n");

		while (1) {
			pause();
		}
	}
	else {
		printf("I'm the parent with parent_id : %d and child_id : %d.\n", getpid(), pid);

		sleep(3);

		if (kill(pid, SIGUSR1) == -1) {
			perror("Kill failed : \n");
			exit(EXIT_FAILURE);
		}

		wait(NULL);
		exit(0);
	}


}
