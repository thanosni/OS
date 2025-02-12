#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
	int fd[2];
	size_t bytes;
	pid_t pid;
	char str[] = "Hello from parent process!";
	char read_buffer[100];

	if (pipe(fd) > 0) {
		perror("Pipe failed.\n");
		exit(1);
	}
	
	pid = fork();

	if (pid < 0) {
		perror("Fork() failed.\n");
		exit(1);
	}

	if (pid == 0) {
		close(fd[1]);
		bytes = read(fd[0], read_buffer, sizeof(read_buffer));
		if (bytes <= 0) {
			perror("Read failed.\n");
			exit(1);
		}
		printf("Recieved string : %s\nBytes read : %lu.\n", read_buffer, bytes);
	}
	else {
		close(fd[0]);
		write(fd[1], str, sizeof(str));
	}
	wait(NULL);
	return 0;

}
