/* 
  PRINTING THE PID of the process which intiated the signal using siginfo structure
*/
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

struct sigaction act;
struct sigaction old_hndlr;

void sighandler(int signum, siginfo_t *info, void *ptr)
{
    printf("Received signal %d\n", signum);
    printf("Signal originates from process %lu\n",
        (unsigned long)info->si_pid);

    printf("\n now assigning the default handler to the signal using sigacton function ");
    sigaction(SIGTERM, &old_hndlr, NULL);
    printf("\n sendignt he signal t the same process using kill func ");
    kill(getpid(), SIGTERM);

}

int main()
{
    printf("I am %lu\n", (unsigned long)getpid());

    memset(&act, 0, sizeof(act));

	/* Use the sa_sigaction field because the handles has two additional parameters */
    act.sa_sigaction = sighandler;

	/* The SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler. */
    act.sa_flags = SA_SIGINFO;

//    sigaction(SIGTERM, &act, NULL);
     sigaction(SIGTERM, &act, &old_hndlr);


    // Waiting for CTRL+C...
    sleep(100);

    return 0;
}
