#pragma once

#include <vector>
#include <cstddef>

#include "math/ray.h"
#include "scene/scene.h"
#include "math/vec3.h"

namespace vkcut {

    class Engine {
        public:
            Engine(size_t width, size_t height);
            ~Engine();
            
            void render(const Scene& scene);

            Vec3 trace_ray(const Ray& ray, const Scene& scene, size_t depth);

        private:
            size_t width, height;
            std::vector<Vec3> framebuffer;

    };

} // namespace vkcut
