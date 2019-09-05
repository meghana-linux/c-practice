#include <stdio.h>

#include <timer.h>
fun1(){
      printf("I am still cool "); 
}

int main(){
   run(10,&fun1); // Should register & execute the function fun1 every 10 seconds
 return 0x0;
}
