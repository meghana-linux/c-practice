/* 
shows an example of when sigabort will be generated 

Among all signal only abort() gets exectued twice even if it invokded once ==> User handler if present and then the default handler

*/


#include<stdio.h>
#include <signal.h>



void sighand( int sig_num){

	printf(" abort signal rec'd \n");

	printf(" We can use this to perform clean up op's\n");
//abort();   //enable this line and check the output
}



main(){

	signal(SIGABRT,sighand);

	printf(" some thing has gone worng\n");

	abort();

	printf(" can you see this\n");

}


