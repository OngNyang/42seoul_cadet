#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 3

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
	int id = *(int*) arg;
	int left_chopstick = id;
	int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;

	// Think
	printf("Philosopher %d is thinking\n", id);
	usleep(30);

	// Pick up chopsticks
	pthread_mutex_lock(&chopsticks[left_chopstick]);
	printf("Philosopher %d picks up left chopstick : %d\n", id, left_chopstick);
	usleep(30);

	pthread_mutex_lock(&chopsticks[right_chopstick]);
	printf("Philosopher %d picks up right chopstick : %d\n", id, right_chopstick);
	usleep(30);

	// Eat
	printf("Philosopher %d is eating\n", id);
	usleep(30);

	// Put down chopsticks
	pthread_mutex_unlock(&chopsticks[left_chopstick]);
	printf("Philosopher %d puts down chopstick %d\n", id, left_chopstick);
	usleep(30);

	pthread_mutex_unlock(&chopsticks[right_chopstick]);
	printf("Philosopher %d puts down chopstick %d\n", id, right_chopstick);
	usleep(30);


	return NULL;
}

int main()
{
	pthread_t	philosophers[NUM_PHILOSOPHERS];
	int	philosopher_ids[NUM_PHILOSOPHERS];

	// Initialize chopsticks mutexes
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_mutex_init(&chopsticks[i], NULL);
		printf("init chopsticks : %d\n", i);
	}

	// Create philosopher threads
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		philosopher_ids[i] = i;
		pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
	}

	// Wait for philosopher threads to finish
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_join(philosophers[i], NULL);
	}

	// Destroy chopsticks mutexes
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_mutex_destroy(&chopsticks[i]);
	}

	return 0;
}
