#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1_function(void *arg);
void *thread2_function(void *arg);

int main() {
    pthread_t thread1, thread2;
    int thread1_ret, thread2_ret;

    // Create Thread T1
    pthread_create(&thread1, NULL, thread1_function, NULL);

    // Create Thread T2
    pthread_create(&thread2, NULL, thread2_function, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

// Thread T1 function: Creates a file named "Thread.txt"
void *thread1_function(void *arg) {
    FILE *fp;
    fp = fopen("Thread.txt", "w");
    if (fp == NULL) {
        perror("Error creating file");
        pthread_exit(NULL);
    }
    fclose(fp);
    pthread_exit(NULL);
}

// Thread T2 function: Writes "Hello its T2" into the "Thread.txt" file
void *thread2_function(void *arg) {
    FILE *fp;
    fp = fopen("Thread.txt", "a"); // Open the file in append mode
    if (fp == NULL) {
        perror("Error opening file");
        pthread_exit(NULL);
    }
    fprintf(fp, "Hello its T2\n");
    fclose(fp);
    pthread_exit(NULL);
}

