
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("Stuff\n");
	fork();
	return 0;
}
