/******************************************************************************
* This is used to demonstrate how to use callback functions
*
* COMPILATION: gcc -o 13_callback 13_callback.c
*
* REFERENCE:
* 1. https://www.cnblogs.com/jiangzhaowei/p/9129105.html
* 2. https://www.runoob.com/w3cnote/c-callback-function.html (the same as 1)
* 3. https://www.runoob.com/cprogramming/c-fun-pointer-callback.html
* 4. 函数名与函数指针 https://www.cnblogs.com/cat-final/p/9415393.html
******************************************************************************/

#include <stdio.h>

//******************************************************************************
// This line can be put in some other header file
// Note the difference between function and function pointer
typedef void (*callback_type)(int);
//******************************************************************************

//******************************************************************************
// This part is often implemented by some library whose source code can NOT be
// exposed to application programs.
int Library_Function(callback_type func_ptr, int y) {
  printf("Entering Library Function.\n");
  (*func_ptr)(y);
  printf("Leaving Library Function.\n");
}
//******************************************************************************

void Callback_1(int x) { // Callback Function Implementation 1
  printf("Hello, this is Callback_1: x = %d\n", x);
}

void Callback_2(int x) { // Callback Function Implementation 2
  printf("Hello, this is Callback_2: x = %d\n", x);
}

void Callback_3(int x) { // Callback Function Implementation 3
  printf("Hello, this is Callback_3: x = %d\n", x);
}

int main() {
  int a = 2, b = 4;
  printf("Entering Main Function.\n");
  Library_Function(Callback_1, a);
  Library_Function(Callback_2, b);
  Library_Function(Callback_3, 8888);
  printf("Leaving Main Function.\n");
  return 0;
}
