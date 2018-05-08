#include <signal.h>



/* When a stop signal arrives, set the action back to the default

   and then resend the signal after doing cleanup actions. */



void

tstp_handler (int sig)

{

  signal (SIGTSTP, SIG_DFL);

  /* Do cleanup actions here. */


  raise (SIGTSTP);

}



/* When the process is continued again, restore the signal handler. */



void

cont_handler (int sig)

{

  signal (SIGCONT, cont_handler);

  signal (SIGTSTP, tstp_handler);

}



/* Enable both handlers during program initialization. */



int

main (void)

{

  signal (SIGCONT, cont_handler);

  signal (SIGTSTP, tstp_handler);


}
