#include <stdio.h>
#include <sys/time.h>	// for gettimeofday()
#include <unistd.h>	// for sleep()

// C program to find the execution time of code
int main()
{
	struct timeval start, end;

	gettimeofday(&start, NULL);

	// do some stuff here
	sleep(5.30);
	
	gettimeofday(&end, NULL);

	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

	printf("Time elpased is %d seconds and %d micros\n", seconds, micros);

	printf("\n Actual struct timeval values ==> %d  ,  %d  :	%d, 	%d	\n",start.tv_sec, end.tv_sec, start.tv_usec, end.tv_usec);
	return 0;
}
