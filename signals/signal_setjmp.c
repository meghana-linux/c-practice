/** setjmp.c - Experiment with setjmp and longjmp */

#include <setjmp.h>
#include <stdio.h>
#include <signal.h>

static jmp_buf env;


void handler(int s) {
    printf("In the handler\n");
    siglongjmp(env, 1);
}

int main(int argc, char * argv[]) {
//    signal(13, handler);
    signal(SIGTERM, handler);
    if (sigsetjmp(env, 1) == 0) {
	// Normal execution, after success in setting the jump environment
	// Infinite loop 
	while (1) 
	    ;
    }
    // We are getting here because of a long jmp
    printf("After long jump\n");
    return 0;
}
