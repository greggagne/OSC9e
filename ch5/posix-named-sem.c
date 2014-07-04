/**
 * Example illustrating POSIX named semaphores
 *
 * Compilation (on OS X):
 *
 *	gcc -lpthread posix-named-sem.c
 *
 * This example includes the appropriate error checking
 * that is not covered in the text.
 *
 * This program illustrates POSIX named semaphores which
 * work on OS X systems.
 *
 * Operating System Concepts - Ninth Edition
 * John Wiley & Sons - 2013.
 */

#include <unistd.h>     
#include <sys/types.h>  
#include <errno.h>      
#include <stdio.h>      
#include <stdlib.h>     
#include <pthread.h>    
#include <string.h>     
#include <semaphore.h>  

int main(void)
{
sem_t *sem;

    /**
     * Create a named semaphore called 'OSC'
     */

    // first remove the semaphore if it already exists
    if (sem_unlink("OSC") == -1)
        printf("Error removing %s\n",strerror(errno));

    // create and initialize the semaphore
    if ( (sem = sem_open("OSC", O_CREAT, 0666, 1)) == SEM_FAILED)
        printf("Error creating %s\n",strerror(errno));

	if (sem_wait(sem) != 0)
       printf("Error waiting %s\n",strerror(errno));

    printf("*** Critical Section *** \n");

	if (sem_post(sem) != 0)
        printf("Error posting %s\n",strerror(errno));

    printf("*** Non-Critical Section *** \n");

    return 0;
}
