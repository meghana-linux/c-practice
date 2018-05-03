#include<stdio.h>
#include<string.h>

#if 0
int main(void)
{
      char src[5];
      char dst[12] = {0};
      memcpy(dst,src,12);
}
#endif

int main(void)

{

      char *src = NULL;

      char dst[12] = {0};

//      memcpy(dst,src,12);
						
	memov(dst,src,12);
}


