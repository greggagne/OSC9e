/**
 * Example illustrating POSIX unnamed semaphores
 *
 * Compilation (on Linux):
 *
 *	gcc -lpthread posix-sem.c
 *
 * This example includes the appropriate error checking
 * that is not covered in the text.
 *
 * Note that OS X does not support unnamed sempahores
 * so this program will not work on those systems.
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
sem_t sem;

    if (sem_init(&sem,0,1) == -1)
              printf("%s\n",strerror(errno));

	if (sem_wait(&sem) != 0)
              printf("%s\n",strerror(errno));

        printf("*** Critical Section *** \n");

	if (sem_post(&sem) != 0)
              printf("%s\n",strerror(errno));

        printf("*** Non-Critical Section *** \n");

	if (sem_destroy(&sem) != 0)
              printf("%s\n",strerror(errno));

        return 0;
}
