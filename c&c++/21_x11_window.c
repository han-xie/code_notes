/* REFERENCE:
 * https://linuxgazette.net/78/tougher.html
 *
 * ADVANTAGE:
 * Compilable in most Linux operating systems, tested in
 * Ubuntu / Debian / Fedora / CentOS
 *
 * COMPILATION:
 * gcc 21_x11_window.c -lX11 -o x11_window
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main(int argc, char **argv)
{
  Display *dpy;
  int screen;
  Window win;
  XEvent event;
  dpy = XOpenDisplay(NULL);
  if(dpy == NULL)
  {
    fprintf(stderr, "Cannot open display\n");
    exit(1);
  }

  screen = DefaultScreen(dpy);

  win = XCreateSimpleWindow(dpy, RootWindow(dpy, screen),
      100, 100, 500, 300,
      1, BlackPixel(dpy, screen), WhitePixel(dpy, screen));
  XSelectInput(dpy, win, ExposureMask | KeyPressMask);
  XMapWindow(dpy, win);

  while(1)
  {
    XNextEvent(dpy, &event);

  }

  return 0;
}
