#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int
main(void)
{
   struct dirent **namelist;
   int n;

   n = scandir("/media/asmaitha/ADRV9009_Profiles", &namelist, 0, alphasort);
   if (n < 0)
       perror("scandir");
   else {
       while (n--) {
       printf("%s\n", namelist[n]->d_name);
       free(namelist[n]);
       }
       free(namelist);
   }
}

