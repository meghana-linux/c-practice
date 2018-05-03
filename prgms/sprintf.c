
#if 0
#include <stdio.h>

int main()
{

	char str[80];
	int val=960;
	sprintf(str, "/sys/class/gpio/gpio%d/value",val);

	printf("\n so %s \n",str);

	return 0;

}
#endif




#if 1
#include <stdio.h>
char str[50];

#define CPLD_RESET 960
#define CPLD_CONFIG 961

//#define sysfs(str,export,gpio) sprintf(str, "/sys/class/gpio/gpio%d/%s",gpio,export);
#define sysfs(str,export,gpio) snprintf(str,sizeof(str), "/sys/class/gpio/gpio%d/%s",gpio,export);


int main()
{

	sysfs(str,"export",CPLD_RESET);
        printf("\n so %s \n",str);

	sysfs(str,"export",CPLD_CONFIG);
        printf("\n so %s \n",str);


        sysfs(str,"direction",CPLD_RESET);
        printf("\n so %s \n",str);

        sysfs(str,"direction",CPLD_CONFIG);
        printf("\n so %s \n",str);



        sysfs(str,"value",CPLD_RESET);
        printf("\n so %s \n",str);

        sysfs(str,"value",CPLD_CONFIG);
        printf("\n so %s \n",str);

//	printf("\n itoa %s \n",itoa(CPLD_CONFIG));
        return 0;
}

#endif




#if 0

#include <stdio.h>
char str[50];

#define STRCAT(a,b) a##b

int val=960;

int main()
{

	STRCAT(export,val);
	printf("\n so %s \n",str);



}
#endif
