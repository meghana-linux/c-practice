#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void exit_handler(void )
{
	printf("\n inside exit handler\n");
}

void signal_func(int sig_num)
{
	printf ("\n inside local signal ahndler %d \n",sig_num);
	signal(SIGINT, SIG_DFL);
}

void signal_func1(int sig_num)
{
        printf ("\n inside local signal ahndler %d \n",sig_num);
        (void)signal(SIGFPE, SIG_DFL);
}

void user_handler(int sig_num)
{
	printf("\n in signal handler - %d\n",sig_num);
}

int main()
{
	if(atexit(exit_handler)!=0)
		{
			printf("\n registering exit handler failed \n");
			_exit(0);
		}

	(void) signal(SIGINT, signal_func);

#if 0
	(void) signal(SIGFPE, signal_func1); 
	int a = 12, b = 0, result; result = a / b; printf("Result is : %dn",result);
        int aa = 12, bb = 0, result1; result1 = aa / bb; printf("Result1 is : %dn",result1);
#endif

/*
	struct sigaction act;
	act.sa_handler = user_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGUSR1, &act, 0);
*/


//	while(1)
		printf("\n hello world");


	sigset_t curtasksiget;
	int err;
	if(sigprocmask(0,NULL,&curtasksiget)<0)
		printf("\n error\n");

	if(sigismember(&curtasksiget, SIGINT))
		printf("\n SIGINT is nto blocked\n");
	else
		printf("\n SIGINT is blocked \n");


        if(sigismember(&curtasksiget, SIGSEGV))
                printf("\n SIGSEGV is nto blocked\n");
        else
                printf("\n SIGSEGV is blocked \n");

        if(sigismember(&curtasksiget, SIGALRM))
                printf("\n SIGINT is nto blocked\n");
        else
                printf("\n SIGINT is blocked \n");
	
	return 0;
}
