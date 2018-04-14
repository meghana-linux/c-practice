/*




*/
#include <stdio.h>

#include <sys/types.h>



main()

{

  int *buf;

  int i, sz;



  i = 1000;

  printf("sbrk(0) = 0x%x\n", sbrk(0));

  for (sz = 4; sz < 32; sz += 4) {

    buf = (int *) malloc(sz);

    buf[0] = i;

    i++;

  printf("Allocated %d bytes.  buf = 0x%x, buf[-1] = %d, buf[-2] = %d, buf[0] = %d\n", 

            sz, buf, buf[-1], buf[-2], buf[0]);

  }



  sz = 100;

  buf = (int *) malloc(sz);

  buf[0] = i;

  i++;

  printf("Allocated %d bytes.  buf = 0x%x, buf[-1] = %d, buf[-2] = %d, buf[0] = %d\n", 

            sz, buf, buf[-1], buf[-2], buf[0]);

  printf("sbrk(0) = 0x%x\n", sbrk(0));

}
