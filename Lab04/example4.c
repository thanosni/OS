#include <stdio.h>
#include <stdlib.h> 
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
	printf("\nRecieved SIGINT (signal %d), but ignoring it.\n", sig);
}

int main() {
	if(signal(SIGINT, sigint_handler) == SIG_ERR) {
		perror("signal");
		exit(EXIT_FAILURE);
	}

	printf("Process ID: %d\n", getpid());
	printf("Press Ctrl+C to attemt to send SIGINT.\n");

	while (1) {
		printf("Running... Try pressing Ctrl+C.\n");
		sleep(2);
	}

	return 0;
}
