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
 * the child shell to exit.
 */

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
#include <netdb.h>

int main(int argc, char **argv);


/* \brief Cleanup function to restore terminal settings and collect shell exit status
 */
void exitCleanUp();

/* \brief Signal handler designed to catch SIGCHLD and SIGPIPE 
 */
void signalHandler(int SIGNUM);

/* \brief Changes terminal into byte-at-a-time non canonical input mode.
 */
void setTerminalToNonCanonicalInput();

void sendBytesToSocket();

void recieveBytesFromSocketAndPrint();

void logToFile(char *buff, int nBytes, int sendMode);

int writeBytesToTerminal(char *buff, int nBytes);

void *readBytesFromSocket();

void *forwardDataToSocket();
