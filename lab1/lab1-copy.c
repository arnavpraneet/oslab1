#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	fork();
	printf("Hello Class!!\nPID=%d\n", getpid());
}
