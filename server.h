/* \file lab1.h
 * \author Jesse Joseph
 * \email jjoseph@hmc.edu
 * \ID 040161840
 * \brief Interface for lab1.c
 *
 * The lab1a program converts the terminal to non-canonical input
 * and echos written characters back.
 *
 * Adding the --shell option opens a bash shell in a child process,
 * and writing commands into the lab1a program interface functions
 * similarly to writing them into the bash prompt. Output from the 
 * bash shell is sent back to the terminal.
 *
 * To quit the program:
 * Send the EOF character with ctrl-D.
 *
 * Sending ctrl-c sends a SIGINT to the child shell, which forces
 * the child shell to exit. I don't believe this is what was 
 * intended by the assignment
 */

#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <getopt.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>

int main(int argc, char **argv);

void serve(int sockfd);

void execShell();

void communicateWithShell();

void *forwardDataToShell();

int sendBytesToShell(char *buff, int nBytes);

int writeBytesToTerminal(char *buff, int nBytes);

void *readBytesFromShell();

void setTerminalToNonCanonicalInput();


/* \brief Cleanup function to restore terminal settings
 */
void exitCleanUp();

/* \brief Signal handler designed to catch SIGCHLD and SIGPIPE 
 */
void signalHandler(int SIGNUM);

void collectShellStatus();

/* \brief Changes terminal into non canonical input mode.
 */
void setTerminalToNonCanonicalInput();

