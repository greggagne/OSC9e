/**
 * Solution to exercise 3.2
 *
 * The answer is easily determined by counting 
 * the number of unique processes which are output
 * by the call to getpid() - which is 8 unique processes.
 */

#include <stdio.h>

int main()
{
	printf("%d\n",getpid());
	fork();
	printf("%d\n",getpid());
	

	fork();
	printf("%d\n",getpid());

	fork();
	printf("%d\n",getpid());

	return 0;
}
