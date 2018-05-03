#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct tid_data{
	int roll_num;
	char name[20];
	pthread_mutex_t tid1_lock;
};

struct tid_data TID1_data;	

void  exit_handler(void)
{

	printf("\n in MAIN exit handler \n");
}

pthread_t tid1, tid2;


void * tid1_func(void *ab)
{

	struct tid_data *tmp = (struct tid_data *)ab;
	tmp->roll_num = 456;
	printf("\n in tid1 func %d \n", tmp->roll_num) ;

}


int main()
{
	int val=99;
	int ret;
	char name[]="asm";


	//register atexit
	if(atexit(exit_handler)!=0)
		{
			printf("\n atexit handler failed \n");
			abort();	//for testing			
	
		}	
	TID1_data.roll_num = 123;
	strcpy(TID1_data.name, "asm");

	printf("\n so %s \n", TID1_data.name);
//	TID1_data.name = "asm";


	ret = pthread_create(&tid1, NULL, tid1_func, &val);
	printf("\n ret is %d \n",ret);
	if(ret !=0)
		{

			printf("\n TID1 fail \n");
			exit(0);
		}



	printf("\n in main thread : %d  %s   %u \n",TID1_data.roll_num, TID1_data.name, (unsigned int)pthread_self() ); //TID1_data.tid1_lock);

	//exit(0);
//	abort();
	return 0;

}
