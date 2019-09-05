#include <stdio.h>
#include <stdlib.h>


void *OneMinuteCall(void *param);
pthread_t thread0;

static int gRunning = 1;

void* OneMinuteCall( void * param )
{
    int delay = (int)param;
    while(gRunning)
    {
        some_func();//periodic function
        sleep(delay);//sleep for 1 minute
    }
}

void some_func(void)
{
    //some stuff
        printf("\n Loading the profile \n");
}

int main(void)
{
    int delay = 60; //(s)

    while(1)
	{
	    sleep(3);	//sleep for 3mins
	    
}
    return 0;
}

