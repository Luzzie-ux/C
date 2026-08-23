#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdio.h>

int main(void)
{
	Display *display;
	Window window;
	int screen;

	display = XOpenDisplay(NULL);
	if (!display)
		return (fprintf(stderr, "Cannot open X display\n"));
	screen = DefaultScreen(display);

	unsigned long black = BlackPixel(display, screen);
	unsigned long white = WhitePixel(display, screen);
	window = XCreateSimpleWindow(
		display,RootWindow(display, screen),100,100,800,600,0,white,black
	);

	XMapWindow(display, window);
	XFlush(display);
	while (getchar() != 'q') {
	}

	XDestroyWindow(display, window);
	XCloseDisplay(display);
	return (0);
}
