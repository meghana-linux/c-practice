// https://stackoverflow.com/questions/32955980/run-a-command-every-x-minutes-in-c

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
    pthread_create(&thread0, NULL, OneMinuteCall, delay);
    //do some other stuff
    //at some point you must set gRunning == 0 to exit loop;
    //then terminate the thread

    return 0;
}
