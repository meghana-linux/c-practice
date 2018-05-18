/*

 * sigaction()

 *

*/



#include <stdio.h>

#include <unistd.h>

#include <signal.h>

#include <stdlib.h>

#include <errno.h>

#include <string.h>



#define DEATH(mess) { perror(mess); exit(errno); }



/* our signal handlers */



void sig_int (int what)

{

    printf ("We have received SIGINT: Will sleep for 2 seconds and continue\n");

    sleep (10);

    printf (" done sleeping 2 seconds\n");

}



void sig_quit (int what)

{

    printf ("We have received SIGQUIT: Aborting.\n");

    abort ();

}



int main (int argc, char *argv[])

{

    struct sigaction act;



    memset (&act, 0, sizeof (act));



    /* Install signal handlers */

    act.sa_handler = sig_int;

    if (sigaction (SIGINT, &act, NULL) < 0) /* for CTRL-C */

        DEATH ("sigaction");



    printf ("Successfully installed signal handler for SIGINT\n");



    act.sa_handler = sig_quit;

    if (sigaction (SIGQUIT, &act, NULL) < 0)    /* for CTRL-\ */

        DEATH ("sigaction");



    printf ("Successfully installed signal handler for SIGQUIT\n");



    /* Do something pointless, forever */

    for (;;) {

        printf ("This is a pointless message.\n");

        sleep (1);

    }



    exit (0);

}


