#include <dirent.h>
#include <stdio.h>

char name[256][256];

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  int count = 0;
  int index = 0;
//  d = opendir(".");

  d = opendir("/home/awt/Documents/personal/c-practice/");

  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
      strcpy(name[count],dir->d_name);
      count++;
    }

    closedir(d);
  }

  while( count > 0 )
  {
      printf("The directory list is %s\r\n",name[index]);
      index++;
      count--;
  }

  return(0);
}
