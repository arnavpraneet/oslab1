#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void d() {
	fork();
	fork();
	printf("Hello Class!!\nPID=%d\n", getpid());
}

int main(){
	d();
	printf("Hello Class!!\nPID=%d\n", getpid());
	exit(0);
}
