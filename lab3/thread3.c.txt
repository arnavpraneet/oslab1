#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>


void *thread_function(void *arg);
int num[2] = {3,5};
int main(){
	pthread_t a_thread;
	void* result;
	pthread_create(&a_thread, NULL, thread_function, (void *)num);
	pthread_join(a_thread, &result);
	printf("Inside the main program\n");
	printf("thread return: %s \n", (char*)result);
}
void *thread_function(void *arg){
	printf("Inside the thread\n");
	int *x = arg;
	int sum = x[0]+x[1];
	printf("sum %d\n", sum);
	pthread_exit("sum_calculated");
}
