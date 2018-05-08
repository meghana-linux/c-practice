/*
HOW TO HANDLE SIGSEGV ANN LATER ALSO GENERATE A CORE UDM 
 This program starts with registering a signal handler. Once you get the signal, inside of the signal handler, set signal handler for the signal to SIG_DFL. Then send yourself same signal, using kill() system call. 
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void sighandler(int signum)
{
    printf("Process %d got signal %d\n", getpid(), signum);
    printf("\n now sending the same SIGNAL with default handler (pid = %u )\n", getpid());	
    signal(signum, SIG_DFL);
    kill(getpid(), signum);
}

int main()
{
    signal(SIGSEGV, sighandler);
    printf("Process %d waits for someone to send it SIGSEGV\n",
        getpid());
    sleep(1000);

    return 0;
}

