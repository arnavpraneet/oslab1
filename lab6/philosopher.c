#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5

pthread_t philosophers[NUM_PHILOSOPHERS];
sem_t forks[NUM_PHILOSOPHERS];
sem_t mutex;

void *philosopher(void* arg){
	int id = *((int *)arg);
	int left_fork = id;
	int right_fork = (id+1) % NUM_PHILOSOPHERS;
	while(1){
		printf("Philosopher %d is thinking.\n", id);
		sem_wait(&mutex);
		sem_wait(&forks[left_fork]);
		sem_wait(&forks[right_fork]);
		sem_post(&mutex);
		printf("Philosopher %d is eating.\n", id);
		sleep(2);
		sem_post(&forks[left_fork]);
		sem_post(&forks[right_fork]);
		printf("Philosopher %d finished eating.\n", id);
	}
}

int main() {
	int i, philosopher_id[NUM_PHILOSOPHERS];
	sem_init(&mutex, 0, 1);
	for(int i = 0; i<NUM_PHILOSOPHERS; i++){
		sem_init(&forks[i], 0, 1);
	}
	for(int i = 0; i<NUM_PHILOSOPHERS; i++){
		philosopher_id[i] = i;
		pthread_create(&philosophers[i], NULL, philosopher, &philosopher_id[i]);
	}
	for(int i = 0; i<NUM_PHILOSOPHERS; i++){
		pthread_join(philosophers[i], NULL);
	}
	for(int i = 0; i<NUM_PHILOSOPHERS; i++){
		sem_destroy(&forks[i]);
	}
	sem_destroy(&mutex);
}
