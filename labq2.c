#include <stdio.h> 
#include <unistd.h>
int main() { 
	int pid = fork(); // Create a child process
	if (pid < 0) { 
		fprintf(stderr, "Fork failed\n"); 
		return 1;
	}
	else if (pid == 0) { // This code runs in the child process 
		printf("CHILD PROCESS. PID: %d\n", getpid());
		
	} else { // This code runs in the parent process 
		printf("PARENT PROCESS. PID: %d\n", getpid());
	} 
	return 0;
}
