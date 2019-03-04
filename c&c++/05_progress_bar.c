/* This is a sample code I found from internet around 28/01/2015, HOWEVER, 
 * I cannot find the original source now.
 * Many thanks to the original author (in some forums, I think).
 * Any suggestion about the original source will be warmly welcomed.
 *
 * COMPILATION: gcc -o 05_progress_bar 05_progress_bar.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int N_max=100, i, j;
  char pstr[1024];
  float total_percent;
  printf("Showing program progress...\n");
  for (i=0;i<=N_max; i++) {
    total_percent = (float)i/N_max*100;
    sprintf(pstr, "Total %6.2f%s", total_percent, "%");
    strcat(pstr, "\t[");
    for(j=0; j<total_percent/100*50; j++) {
      strcat( pstr, "=");  
    }
    for(;j<50; j++) {
      strcat( pstr, " " );
    }
    strcat( pstr, "]" );
    fflush(stdout);
    for(j=0; j<(strlen(pstr)*1.5); j++) {
      printf("\b");
    }  
    printf("%s", pstr);
    usleep(100000);
  }
  printf("\n");
}
