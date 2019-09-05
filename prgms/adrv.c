#include <dirent.h>
#include <stdio.h>

char name[256][256];

int main(int argv, char*argc[])
{

  int no_of_sec_fr_each_profile = atoi(argc[1]);
  printf("\n SO %d /n", no_of_sec_fr_each_profile);

  char *command = malloc(sizeof(char) * 500) ;
  int profile_count=0;

  DIR           *d;
  struct dirent *dir;
  int count = 0;
  int index = 0;

  d = opendir("/media/asmaitha/ADRV9009_Profiles");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
      if( strstr(dir->d_name, ".txt") != NULL)
                {
                        strcpy(name[count],dir->d_name);
                        count++;
                }
    }

    closedir(d);
  }

  profile_count = count ;

  while( count > 0 )
  {
      printf("The directory list is %s\r\n",name[index]);
      index++;
      count--;
  }


  count = profile_count;
  index = 0;

 // while(count > 0 )
  {

        //executing profile

        sprintf(command, "cat %s > /sys/bus/iio/devices/iio:device3/profile_config ", name[index]) ;
        printf("\ncat command...   %s \n \n \n", command );
        system(command);

        index++;
        count--;

        printf("\\n before sleep in while loop ");

//        sleep(no_of_sec_fr_each_profile);
        printf("\\n in while loop ");



  }


















  return(0);
}




