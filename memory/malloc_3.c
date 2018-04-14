/*
 each return value from malloc() is 16 bytes greater than the previous one. we might expect it to be only 4 bytes greater since it is only allocating 4 bytes. What is happening is that malloc() allocates some extra bytes each time it is called so that it can do bookkeeping. These extra bytes help out when free() is called

*/






#include <stdio.h>

int main()

{

  int j, *buf;



  for (j = 0; j < 10; j++) {

    buf = (int *) malloc(4);

    printf("malloc(4) returned 0x%x\n", buf);

  }

}
