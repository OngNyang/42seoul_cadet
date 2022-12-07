#include <stdarg.h>
#include <stdio.h>

double avg(double value, ...)
{
	double	sum = 0;
	int		num = 0;
	va_list	ap;
	va_start(ap, value);
	while (value != 0.0)
	{
		sum  += value;
		num++;
		value = va_arg(ap, double);
	}
	va_end(ap);
	return (sum / num);
}

int main (void)
{
	printf("result : %.31f", avg(1.01, 34.02, 7.45, 0.0));
	return (0);
}