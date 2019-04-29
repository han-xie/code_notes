/* This is used to check the endianness of LINUX operating systems
 * THANKS to SDL (Simple DirectMedia Layer):
 * https://www.libsdl.org
 *
 * REFERENCE:
 * https://www.libsdl.org/release/SDL-1.2.15/include/SDL_endian.h
 *
 * COMPILATION: gcc -o 09_endianness 09_endianness.c
 */

#include <stdio.h>

#ifdef __linux__
#include <endian.h>
#else
# error only linux is supported
#endif /* __linux__ */

int main() {
#ifdef __linux__
  if (__BYTE_ORDER == __BIG_ENDIAN) printf("This machine is big endian.\n");
  else if (__BYTE_ORDER == __LITTLE_ENDIAN) printf("This machine is little endian.\n");
#endif

  return 0;
}
