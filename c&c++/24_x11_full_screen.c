/* 
 * This is a sample code to set full-screen with X11
 *
 * REFERENCES:
 * https://blog.csdn.net/onlyou930/article/details/6549333
 * https://stackoverflow.com/questions/660613/how-do-you-hide-the-mouse-pointer-under-linux-x11
 *
 * COMPILATION: gcc 24_x11_full_screen.c -lX11 -o full_screen
 */

#include <stdio.h>

#include <X11/Xlib.h>

int main()
{
    Display *dpy;
    int screen;
    int blackColor, whiteColor;
    Window win;
    XEvent xevt; 
    int posx, posy, width, height;

    dpy = XOpenDisplay(NULL);
    screen = DefaultScreen(dpy);
    blackColor = BlackPixel(dpy, DefaultScreen(dpy));
    whiteColor = WhitePixel(dpy, DefaultScreen(dpy));

    posx = posy = 0;
    width = DisplayWidth(dpy, screen);   /* 获取屏幕宽度 */
    height = DisplayHeight(dpy, screen); /* 获取屏幕高度 */

    win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), posx, posy,
                    width, height, 0, whiteColor, whiteColor);
    /* Settings for full screen */
    XSetWindowAttributes winattrs;
    unsigned long winmask;
    winattrs.override_redirect = True;  // necessary for full screen
    winmask = CWOverrideRedirect; /* 指定只对override_redirect属性做改变 */
    XChangeWindowAttributes(dpy, win, winmask, &winattrs);

    /* Hide cursor: Ref. stackoverflow */
    Cursor invisibleCursor;
    Pixmap bitmapNoData;
    XColor black;
    static char noData[] = { 0,0,0,0,0,0,0,0 };
    black.red = black.green = black.blue = 0;
    bitmapNoData = XCreateBitmapFromData(dpy, win, noData, 8, 8);
    invisibleCursor = XCreatePixmapCursor(dpy, bitmapNoData, bitmapNoData,
                                          &black, &black, 0, 0);
    XDefineCursor(dpy, win, invisibleCursor);
    /* End of hide cursor */

    // We want to get MapNotify events
    XSelectInput(dpy, win, StructureNotifyMask | ExposureMask);

    XMapWindow(dpy, win);
    XFlush(dpy);

    while(1) {
      XNextEvent(dpy, &xevt);
    }
    
    XFreeCursor(dpy, invisibleCursor);
    XFreePixmap(dpy, bitmapNoData);

    return 0;
}
