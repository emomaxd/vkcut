#include <iostream>

#include "engine.h"

namespace vkcut {

    Engine::Engine(size_t width, size_t height) {
        framebuffer.resize(width * height);
    }

    Engine::~Engine() {
    }

    void Engine::render() {
        std::cout << "[Engine]->Rendering...\n";
    }

}
