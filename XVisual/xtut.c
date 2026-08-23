#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 200
#define HEIGHT 300

Display *dis;
int screen;
Window win;
GC gc;
unsigned long chartreuse;

void init_x();
void get_colors();
void close_x();

int main()
{
	init_x();
	get_colors();
	XEvent event;
	KeySym key;
	char text[255];
	while (1)
	{
		XNextEvent(dis, &event);
		if (event.type == KeyPress &&
			XLookupString(&event.xkey, text, 255, &key, 0) == 1)
		{
			if (text[0] == 'q')
			{
				close_x();
			}
			printf("You pressed the %c key!\n", text[0]);
		}
		if (event.type == ButtonPress)
		{
			printf("You pressed a button at (%i,%i)\n",
				   event.xbutton.x,
				   event.xbutton.y);
		}
	}
	return 0;
}

void init_x()
{
	unsigned long black, white;
	dis = XOpenDisplay((char *)0);
	screen = DefaultScreen(dis);
	black = BlackPixel(dis, screen);
	white = WhitePixel(dis, screen);

	win = XCreateSimpleWindow(
		dis, DefaultRootWindow(dis), 0, 0, WIDTH, HEIGHT, 5, white, black);
	XSetStandardProperties(dis, win, "My X Window", "HI!", None, NULL, 0, NULL);
	XSelectInput(dis, win, ButtonPressMask | KeyPressMask);
	gc = XCreateGC(dis, win, 0, 0);
	XSetBackground(dis, gc, white);
	XSetForeground(dis, gc, black);
	XMapRaised(dis, win);
}

void get_colors() {
	XColor tmp;

	XParseColor(dis, DefaultColormap(dis,screen), "chartreuse", &tmp);
	XAllocColor(dis,DefaultColormap(dis,screen),&tmp);
	chartreuse=tmp.pixel;
}

void close_x()
{
	XFreeGC(dis, gc);
	XDestroyWindow(dis, win);
	XCloseDisplay(dis);
	exit(1);
}