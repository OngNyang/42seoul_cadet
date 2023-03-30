# include "philo.h"

/*
- argv should be 4~5
- create 'thread' as many as philosophers. -> pthread_create()
- implement 'forks' with pthread_mutex()
*/

int	main(int argc, char **argv)
{
	pthread_t		philosophers[NUM_PHILOSOPHERS];
	pthread_mutex_t	chopsticks[NUM_PHILOSOPHERS];
	int				philosopher_ids[NUM_PHILOSOPHERS];

	for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }
	


	return (0);
}