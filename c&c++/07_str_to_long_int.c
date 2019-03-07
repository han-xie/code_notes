/* This code shows how to convert a string to long int.
 *
 * REFERENCES:
 * https://stackoverflow.com/questions/9748393/how-can-i-get-argv-as-int
 * http://www.cplusplus.com/reference/cstdlib/strtol
 * 
 * EXAMPLES:
 * 1. uuid-1.6.2/uuid_cli.c: getopt and strtol are used
 *
 * COMPILATION: gcc -o 07_str_to_long_int 07_str_to_long_int.c
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Please provide one argument\n");
    exit(EXIT_FAILURE);
  }
  char* pEnd;
  long result;
  result = strtol(argv[1], &pEnd, 10);
  if (*pEnd != '\0') {
    printf("The argument has to be an integer\n");
    exit(EXIT_FAILURE);
  }
  printf("The argument is %ld, right? Ha~Ha~Ha~\n", result);
  
  return 0;
}

