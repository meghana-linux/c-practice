#include<stdio.h>
#include<string.h>

char final_str[50];

#define str_cat(str1, str2, str3) snprintf(final_str, sizeof(final_str), "%s%s%s" str1, str2, str3);

//#define sysfs(fd_str,str1,str2,str3) snprintf(fd_str,sizeof(fd_str), "/sys/class/gpio/gpio%s/%s/%s",str1,str2,str3);

#define sysfs(str1,str2,str3) snprintf(final_str,sizeof(final_str), "/sys/class/gpio/gpio%s/%s/%s",str1,str2,str3);


int main()
{

    str_cat("hello","world","end");
    printf("\n final str is %s \n", final_str);

    sysfs("hello","world","end");
    printf("\n final str is %s \n", final_str);


	return 0;
}
