#pragma once

#include <cstddef>

#include "math/ray.h"
#include "math/vec3.h"
#include "scene/mesh.h"

namespace vkcut {

    struct HitResult {
        float t;
        Vec3 normal;
        uint32_t material_id;
    };

    struct Scene {
        Mesh* meshes;                // array of meshes
        size_t mesh_count;
        size_t max_mesh_count;
        
        Scene();
        Scene(size_t max_mesh_count);

        ~Scene();

        void add_mesh(const Mesh& mesh);
    
    private:
        void init(size_t max_mesh_count);
        void cleanup();
    };

    bool scene_intersect(const Ray& ray, const Scene& scene, HitResult& hit);

} // namespace vkcut
