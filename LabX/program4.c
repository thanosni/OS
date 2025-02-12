#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;

	FILE *fp = fopen("output.txt", "w");
	if (fp == NULL) {
		perror("Fopen failed : \n");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	
	if (pid == -1) {
		perror("Fork failed : \n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) {
		printf("Child process writing it's id to file.\n");
		fprintf(fp, "Child process id = %d.\n", getpid());
	}
	else {
		printf("Parent process writing it's name to file.\n");
		fprintf(fp, "Parent process id = %d.\n", getpid());
		wait(NULL);
		if (fclose(fp) != 0) {
			perror("Fclose failed : \n");
			exit(EXIT_FAILURE);
		}
		return 0;
	}		
}
