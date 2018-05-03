#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

#include <unistd.h>

#if 1

int main()
{
    fork();
    
    printf("\nHello-World! - %d \n",getpid());
    
    fork();
    
    printf("\n second-hello - %d \n", getpid());

    exit(10);
    //return 0;
}

#endif
