#include <stdio.h> 
#include <unistd.h>
void print_hello_from_parent() { 
	printf("Hello from parent in parent process\n");
}
void print_hello_from_child() {
       	printf("Hello from child in child process\n");
}
int main() { 
	int pid = fork(); // Create a child process
	if (pid < 0) { 
		fprintf(stderr, "Fork failed\n"); 
		return 1;
	}
	else if (pid == 0) { // This code runs in the child process 
		print_hello_from_child();
		
	} else { // This code runs in the parent process 
		print_hello_from_parent();
	} 
	return 0;
}
