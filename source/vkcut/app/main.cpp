#include <X11/Xlib.h>
#include <iostream>

int main() {

    Display* display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cerr << "Cannot open display\n";
        return 1;
    }

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 800, 600, 1, BlackPixel(display, screen), WhitePixel(display, screen));

    XMapWindow(display, window);

    XEvent event;
    while (true) {
        XNextEvent(display, &event);
        if (event.xany.type == ClientMessage) {
            break;
        }
    }

    XCloseDisplay(display);

    return 0;
}
