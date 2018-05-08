/*

sample program that uses sigaltstack to catch infinite recursion. If you comment out the sigaltstack call or SA_ONSTACK flag, the signal handler will not be able to run because it has no stack left and the program will just crash.

*/

#define _XOPEN_SOURCE 700
#include <signal.h>
#include <unistd.h>
void handler(int sig)
{
    write(2, "stack overflow\n", 15);
    _exit(1);
}
unsigned infinite_recursion(unsigned x) {
    return infinite_recursion(x)+1;
}
int main()
{
    static char stack[SIGSTKSZ];
    stack_t ss = {
        .ss_size = SIGSTKSZ,
        .ss_sp = stack,
    };
    struct sigaction sa = {
        .sa_handler = handler,
        .sa_flags = SA_ONSTACK
    };
    sigaltstack(&ss, 0);
    sigfillset(&sa.sa_mask);
    sigaction(SIGSEGV, &sa, 0);
    infinite_recursion(0);
}
