/******************************************************************************
* ACKNOWLEDGEMENT: Blaise Barney
* REFERENCE: https://computing.llnl.gov/tutorials/pthreads/samples/hello.c
* - https://computing.llnl.gov/tutorials/pthreads/ (last accessed 02/03/19)
*   I put it in my github for learning purpose only, please refer to the link
*   above for the original information.
* COMPILATION: gcc -pthread -o 04_hello_pthread 04_hello_pthread.c
* FILE: 04_hello_pthread.c
* DESCRIPTION:
*   A "hello world" Pthreads program.  Demonstrates thread creation and
*   termination.
* AUTHOR: Blaise Barney
* LAST REVISED: 08/09/11
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
