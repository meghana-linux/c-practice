#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

char name[256][256];

int main(int argv, char*argc[])
{

  int no_of_sec_fr_each_profile = ( (atoi(argc[1]) < 0 ) ? 5 : ( atoi(argc[1]) < 0 ) ) ;
  printf("\n so %d ]n", no_of_sec_fr_each_profile) ;

  DIR           *d;
  struct dirent *dir;
  int count = 0;
  int index = 0;
  d = opendir("/home/awt/Documents/5G/ADRV9009_Profiles");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
      if( strstr(dir->d_name, "txt") != NULL)
                {
                        strcpy(name[count],dir->d_name);
                        count++;
                }
    }

    closedir(d);
  }

  while( count > 0 )
  {
      printf("The directory list is %s\r\n",name[index]);
      index++;
      count--;
  }



  while(1)
  {
        sleep( no_of_sec_fr_each_profile);
        printf("\\n in while loop ");
  }




	return 0;
}
