/*  IMP NOTES :

Here, the process is calling the pause function to put it to sleep until a signal is caught. When the

signal is caught, the signal handler just sets the flag sig_int_flag to a nonzero value. The process is

automatically awakened by the kernel after the signal handler returns, notices that the flag is

nonzero, and does whatever it needs to do. But there is a window of time when things can go wrong.

If the signal occurs after the test of sig_int_flag, but before the call to pause, the process could go

to sleep forever (assuming that the signal is never generated again). This occurrence of the signal is

lost. This is another example of some code that isn't right, yet it works most of the time. Debugging

this type of problem can be difficult.

*/
#include<stdio.h>
#include<signal.h>

int sig_status;

void sig_handler(int);

int main()
{
	signal(SIGINT, sig_handler);

// 	while(sig_status == 0)
//		pause();

	return 0;
}


void sig_handler(int sig_num)
{
	printf("\n inside sig handler with sig num %d \n",sig_num);
	
	sig_status = 1;

        signal(SIGINT, sig_handler);

}
