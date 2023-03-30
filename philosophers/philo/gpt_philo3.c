#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

typedef struct s_arg
{
	int			 philo_id;
	pthread_mutex_t *arr_forks;
}			   t_arg;

void *philosopher(void *arg) {
	t_arg *args = (t_arg*) arg;
	int id = args->philo_id;
	pthread_mutex_t *forks = args->arr_forks;

	int left_fork = id;
	int right_fork = (id + 1) % NUM_PHILOSOPHERS;

	// Think
	printf("Philosopher %d is thinking\n", id);
	usleep(30);

	// Pick up forks
	pthread_mutex_lock(&forks[left_fork]);
	printf("Philosopher %d picks up left fork : %d\n", id, left_fork);
	usleep(30);

	pthread_mutex_lock(&forks[right_fork]);
	printf("Philosopher %d picks up right fork : %d\n", id, right_fork);
	usleep(30);

	// Eat
	printf("Philosopher %d is eating\n", id);
	usleep(30);

	// Put down forks
	pthread_mutex_unlock(&forks[left_fork]);
	printf("Philosopher %d puts down fork %d\n", id, left_fork);
	usleep(30);

	pthread_mutex_unlock(&forks[right_fork]);
	printf("Philosopher %d puts down fork %d\n", id, right_fork);
	usleep(30);

	return NULL;
}

int main()
{
	pthread_t philosophers[NUM_PHILOSOPHERS];
	t_arg args[NUM_PHILOSOPHERS];

	pthread_mutex_t forks[NUM_PHILOSOPHERS];
	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_mutex_init(&forks[i], NULL);
	}

	printf("init forks\n");

	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		args[i].philo_id = i;
		args[i].arr_forks = forks;
		pthread_create(&philosophers[i], NULL, philosopher, &args[i]);
	}

	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_join(philosophers[i], NULL);
	}

	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
		pthread_mutex_destroy(&forks[i]);
	}

	return 0;
}
