#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include <setjmp.h>

static jmp_buf buf;
int main()
{
//        volatile int b=3;
int b=3;
        if(setjmp(buf)!=0)
        {
                printf("\n so %d",b);
                exit(0);
        }

        b=5;
        longjmp(buf,1);

}

