
#include <stdio.h> 
#include <dirent.h> 
  
int main(void) 
{ 
	
   int i=0;
   char* profile_name[10];
     profile_name = (char*) malloc( 100* 10);


    struct dirent *de;  // Pointer for directory entry 
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir("."); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
        return 0; 
    } 
  
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
    // for readdir() 
    while ((de = readdir(dr)) != NULL) 
	 {
            printf("\n\n\n%s\n", de->d_name); 
	    strcpy(profile_name[i], de->d_name); 
            printf("%s\n", profile_name[i]); 
	    i++;  
	}

    closedir(dr);     
    return 0; 
} 

