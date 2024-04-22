#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
	int x = 10;
	int pid = fork();
	if(pid ==0){
		printf("Child => PPID:%d PID:%d\n", getppid(), getpid());
		x=x-5;
		printf("x=%d\n", x);
		printf("C_address=%u\n", &x);
		exit(EXIT_SUCCESS);
	}
	else if(pid>0){
		printf("Parent => PID: %d\n", getpid());
		x=x+5;
		printf("x=%d\n", x);
		printf("P_address=%u\n", &x);
		printf("Wating for child process to finish.\n");
		wait(NULL);
		printf("Child process finished");
	}
	else {
		printf("Enable to create child process\n");
	}
	return EXIT_SUCCESS;	
}

