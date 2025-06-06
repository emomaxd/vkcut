#include "engine/engine.h"
#include "renderer/camera.h"

namespace vkcut {
    
    Camera camera; /* TODO: init camera */
    Vec3 background_color(0.0f, 0.0f, 0.0f);

    static Vec3 shade(const HitResult& hit, const Scene& scene) {
        return Vec3(1.0f, 0.0f, 0.0f);
    }



    Engine::Engine(size_t width, size_t height) {
        framebuffer.resize(width * height);
    }

    Engine::~Engine() {
    }

    void Engine::render(const Scene& scene) {
      /* TODO: Remove if or use debug assert */  
      if (scene.mesh_count <= 0) return;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                Ray ray = generate_primary_ray(x, y, width, height, camera);

                HitResult hit;
                if (scene_intersect(ray, scene, hit)) {
                    framebuffer[y * width + x] = shade(hit, scene);
                } else {
                    framebuffer[y * width + x] = background_color;
                }
            }
        }
    }

    Vec3 trace_ray(const Ray& ray, const Scene& scene, size_t depth) {
        return Vec3{};    
    }
}
