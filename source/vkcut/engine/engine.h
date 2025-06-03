#pragma once

#include <vector>
#include <cstddef>

#include "vec3.h"
#include "ray.h"

namespace vkcut {

    class Engine {
        public:
            Engine(size_t width, size_t height);
            ~Engine();
            
            /* TODO: Take scene as parameter */
            void render();

            /* TODO: Take scene as second parameter */
            Vec3 trace_ray(const Ray& ray, size_t depth);


        private:
            size_t width, height;
            std::vector<Vec3> framebuffer;

    };

} // namespace vkcut
