#include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

long long	ft_time(void)
{
	struct timeval	time;
	long long		milli_sec;

	gettimeofday(&time, NULL);
	milli_sec = (time.tv_sec *1000) + (time.tv_usec / 1000);
	printf("%ld\n", time.tv_sec);
	printf("%d\n", time.tv_usec);
	return (milli_sec);
}

int	main(void)
{
	printf("%lld", ft_time());
}