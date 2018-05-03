#include <stdio.h>

int f1(int val)

{

        int *ptr;
        if (val == 0) {
                int val;
                val = 5;
                ptr = &val;
                printf("\n inside if %d \n",val);
        }

        printf("\n after if %d \n",val);
//        return(*ptr);
	return 0;
}


int main()
{

        int x=0;
        int ret = f1(x);
        printf("\n in main %d , ret-%d \n",x,ret);

        return 0;
}
                                                                                                                                                
        
