/*  
register a signal handler
 create a child process using fork(), 
generated the isgnal and print the pid using siginfo_t
*/



#include<stdio.h>
#include<signal.h>

int main()
{
   printf("\n hello - checking signal functionality for a thread \n");

   pidt_t x = fork();
