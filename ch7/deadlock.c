/**
 * A pthread program illustrating deadlock.
 *
 * Usage:
 *	    gcc deadlock.c -lpthread
 *	    ./a.out
 *
 * Figure 7.4
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013.
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;

void *do_work_one(void *param); 
void *do_work_two(void *param); 

int main(int argc, char *argv[])
{
    pthread_t tid1, tid2; /* the thread identifiers */
    pthread_attr_t attr; /* set of attributes for the thread */

    /* get the default attributes */
    pthread_attr_init(&attr);

    /* create the mutex locks */
    pthread_mutex_init(&first_mutex,NULL);
    pthread_mutex_init(&second_mutex,NULL);

    /* create the threads */
    pthread_create(&tid1,&attr,do_work_one,NULL);
    pthread_create(&tid2,&attr,do_work_two,NULL);

    /* now wait for the thread to exit */
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    printf("Parent DONE\n");

    /* destroy the mutex before exiting */
    pthread_mutex_destroy(&first_mutex);
    pthread_mutex_destroy(&second_mutex);
}

/**
 * The first thread worker
 */
void *do_work_one(void *param) 
{
	pthread_mutex_lock(&first_mutex);
    printf("Worker 1 has acquired first mutex\n");
	pthread_mutex_lock(&second_mutex);
    printf("Worker 1 has acquired second mutex\n");

	/**
	 * Do some work
	 */

    printf("Worker 1 is whistling .....\n");

	pthread_mutex_unlock(&second_mutex); 
	pthread_mutex_unlock(&first_mutex); 

    printf("worker 1 done\n");

	pthread_exit(0);
}

/**
 * The second thread worker
 */
void *do_work_two(void *param)
{
        pthread_mutex_lock(&second_mutex);
        printf("Worker 2 has acquired second mutex\n");
        pthread_mutex_lock(&first_mutex);
        printf("Worker 2 has acquired first mutex\n");

        /**
         * Do some work
         *
         */

        printf("Worker 2 is whistling .....\n");

        pthread_mutex_unlock(&first_mutex);
        pthread_mutex_unlock(&second_mutex);

        pthread_exit(0);
}

