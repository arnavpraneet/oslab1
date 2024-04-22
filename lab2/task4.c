#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) created a child process with PID: %d\n", getpid(), child_pid);
        printf("Parent process is sleeping for 10 seconds\n");
        sleep(10); // Sleep for 10 seconds to let the child process become a zombie
        printf("Parent process is exiting\n");
    } else if (child_pid == 0) {
        // Child process
        printf("Child process (PID: %d) is exiting immediately\n", getpid());
        exit(0);
    } else {
        // Error handling if fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Wait for the child process to terminate
    // This will cause the child process to become a zombie until the parent process waits for it
    wait(NULL);

    return 0;
}

