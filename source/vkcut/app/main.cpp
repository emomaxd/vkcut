#include <X11/Xlib.h>
#include <iostream>

#include "engine/engine.h"
#include "scene/scene.h"

int main() {

    constexpr size_t WIDTH = 800, HEIGHT = 600;
    
    const char* filename = "render.obj";

    vkcut::Engine engine(WIDTH, HEIGHT);

    vkcut::Scene scene;
    

/* ================================================================================================================================================================================ */


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
        engine.render(scene);
        XNextEvent(display, &event);
        if (event.xany.type == ClientMessage) {
            break;
        }
    }

    XCloseDisplay(display);

    return 0;
}
