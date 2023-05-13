#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 3

typedef struct s_arg
{
	int				philo_id;
	pthread_mutex_t	*arr_forks;
}				t_arg;


void *philosopher(void *arg) {
	// int id = *(int*) arg;
	// int left_chopstick = id;
	// int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;
	int	id;
	
	id = arg->philo_id;


	// Think
	printf("Philosopher %d is thinking\n", id);
	usleep(30);

	// // Pick up chopsticks
	// pthread_mutex_lock(&chopsticks[left_chopstick]);
	// printf("Philosopher %d picks up left chopstick : %d\n", id, left_chopstick);
	// usleep(30);

	// pthread_mutex_lock(&chopsticks[right_chopstick]);
	// printf("Philosopher %d picks up right chopstick : %d\n", id, right_chopstick);
	// usleep(30);

	// // Eat
	// printf("Philosopher %d is eating\n", id);
	// usleep(30);

	// // Put down chopsticks
	// pthread_mutex_unlock(&chopsticks[left_chopstick]);
	// printf("Philosopher %d puts down chopstick %d\n", id, left_chopstick);
	// usleep(30);

	// pthread_mutex_unlock(&chopsticks[right_chopstick]);
	// printf("Philosopher %d puts down chopstick %d\n", id, right_chopstick);
	// usleep(30);


	return NULL;
}

int	main()
{
	pthread_t	philosophers;

	t_arg	arg;
	arg.philo_id = 0;
	arg.arr_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);

	pthread_mutex_init(arg.arr_forks, NULL);
	printf("init chopsticks\n");

	pthread_create(&philosophers, NULL, philosopher, &arg);

	pthread_join(philosophers, NULL);

	pthread_mutex_destroy(arg.arr_forks);
	// pthread_mutex_destroy(&chopsticks[i]);

}

