#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <dirent.h>
int main(void)
{ FILE *fp;
  DIR *d;
  struct dirent *dir;
  char *filenames[8];
  //char *filenames = malloc(sizeof *filenames);
  int i=0;
  int a;
  d = opendir("revisions");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      //strcpy((char*)(long)filenames[i],(void *)(dir->d_name));
      //*(char**)&filenames[i]=gets(dir->d_name);
    filenames = (char *) malloc(sizeof *filenames);
    strcpy(filenames,dir->d_name);

//      filenames[i]=(dir->d_name);
      printf("%s",filenames[i]);
      //printf("%s",*(char**)&filenames[i]);
      printf("\n");
      i++;
      
    }
    printf("\n");
    closedir(d);
  }
  for (a = 2; a < i; a++){
     //printf(*(char**)&filenames[a]);
     printf("%s",filenames[a]);
     printf("\n");
  }
  return(0);
