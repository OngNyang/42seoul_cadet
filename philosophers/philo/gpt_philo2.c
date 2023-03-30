/*
version that have l and r chopstick
it does not do mutual exclusion..

init chopsticks : 0
init chopsticks : 1
init chopsticks : 2
Philosopher 0 is thinking
Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 0 picks up left chopstick : 0
Philosopher 1 picks up left chopstick : 1
Philosopher 2 picks up left chopstick : 2
Philosopher 0 picks up right chopstick : 1
Philosopher 1 picks up right chopstick : 2
Philosopher 0 is eating
Philosopher 2 picks up right chopstick : 0
Philosopher 1 is eating
Philosopher 0 puts down chopstick 0
Philosopher 2 is eating
Philosopher 1 puts down chopstick 1
Philosopher 0 puts down chopstick 1
Philosopher 2 puts down chopstick 2
Philosopher 1 puts down chopstick 2
Philosopher 2 puts down chopstick 0
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 3

typedef struct {
	pthread_mutex_t left_chopstick;
	pthread_mutex_t right_chopstick;
	int id;
} philosopher_data_t;

void *philosopher(void *arg) {
	philosopher_data_t *data = (philosopher_data_t*) arg;
	int id = data->id;
	int left_chopstick = id;
	int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;

	// Think
	printf("Philosopher %d is thinking\n", id);
	usleep(30);

	// Pick up chopsticks
	pthread_mutex_lock(&data->left_chopstick);
	printf("Philosopher %d picks up left chopstick : %d\n", id, left_chopstick);
	usleep(30);
	pthread_mutex_lock(&data->right_chopstick);
	printf("Philosopher %d picks up right chopstick : %d\n", id, right_chopstick);
	usleep(30);

	// Eat
	printf("Philosopher %d is eating\n", id);
	usleep(30);

	// Put down chopsticks
	pthread_mutex_unlock(&data->left_chopstick);
	printf("Philosopher %d puts down chopstick %d\n", id, left_chopstick);
	usleep(30);

	pthread_mutex_unlock(&data->right_chopstick);
	printf("Philosopher %d puts down chopstick %d\n", id, right_chopstick);
	usleep(30);

	return NULL;
}

int main()
{
	pthread_t			philosophers[NUM_PHILOSOPHERS];
	philosopher_data_t	philosopher_data[NUM_PHILOSOPHERS];

	// Initialize chopsticks mutexes
	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pthread_mutex_init(&philosopher_data[i].left_chopstick, NULL);
		pthread_mutex_init(&philosopher_data[i].right_chopstick, NULL);
		philosopher_data[i].id = i;
		printf("init chopsticks : %d\n", i);
	}

	// Create philosopher threads
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_create(&philosophers[i], NULL, philosopher, &philosopher_data[i]);
	}

	// Wait for philosopher threads to finish
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_join(philosophers[i], NULL);
	}

	// Destroy chopsticks mutexes
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_mutex_destroy(&philosopher_data[i].left_chopstick);
		pthread_mutex_destroy(&philosopher_data[i].right_chopstick);
	}

	return 0;
}
