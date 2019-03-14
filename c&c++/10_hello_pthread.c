/******************************************************************************
* ACKNOWLEDGEMENT: Blaise Barney
* REFERENCES: https://computing.llnl.gov/tutorials/pthreads/samples/hello.c
* - https://computing.llnl.gov/tutorials/pthreads/ (accessed Mar. 02, 2019)
*   I put it in my github for learning purpose only, please refer to the link
*   above for the original information.
* COMPILATION: gcc -pthread -o 10_hello_pthread 10_hello_pthread.c
* FILE: 10_hello_pthread.c
* DESCRIPTION:
*   A "hello world" Pthreads program.  Demonstrates thread creation and
*   termination.
* AUTHOR: Blaise Barney
* LAST REVISED: Aug. 9, 2011
******************************************************************************
* When this program is running,  $ pstree -p [PID] command can be used to view
* thread tree. $ top -Hp [PID] can also be used to view threads.
* [PID] can be found with $ ps -a | grep 04_hello_pthread command.
* REFERENCE: https://www.cnblogs.com/kevingrace/p/5252919.html
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> /* sleep */
#define NUM_THREADS	5

void *PrintHello(void *threadid) {
  long tid;
  tid = (long)threadid;
  sleep(20);
  printf("Hello World! It's me, thread #%ld!\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0;t<NUM_THREADS;t++) {
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

