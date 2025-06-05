#include <cfloat>
#include <cstddef>
#include <cstring>
#include <algorithm>  // std::min

#include "math/ray.h"
#include "math/vec3.h"
#include "scene/scene.h"

namespace vkcut {

    static Vec3 load_vec3(const float* data) {
        return Vec3(data[0], data[1], data[2]);
    }

    Scene::Scene() {
        constexpr size_t MAX_MESH_COUNT = 1024;
        init(MAX_MESH_COUNT);
    }

    Scene::Scene(size_t max_mesh_count) {
        init(max_mesh_count);
    }

    Scene::~Scene() {
        cleanup();
    }

    void Scene::init(size_t max_mesh_count) {
        this->max_mesh_count = max_mesh_count;
        this->mesh_count = 0;
        this->meshes = new Mesh[max_mesh_count];
    }

    void Scene::cleanup() {
        for (size_t i = 0; i < mesh_count; ++i) {
            delete[] meshes[i].vertices;      // Clean up vertices
            delete[] meshes[i].triangles;     // Clean up triangles
        }
        delete[] meshes;
    }

    void Scene::add_mesh(const Mesh& mesh) {
        if (mesh_count < max_mesh_count) {
            meshes[mesh_count++] = mesh;
        } else {
            // Handle overflow, maybe reallocate if needed
            // Note: consider a smarter memory management strategy
        }
    }

    bool scene_intersect(const Ray& ray, const Scene& scene, HitResult& hit) {
        bool any_hit = false;
        float closest_t = FLT_MAX;

        // Perform intersection tests for each mesh in the scene
        for (size_t mi = 0; mi < scene.mesh_count; ++mi) {
            const Mesh& mesh = scene.meshes[mi];
            for (size_t ti = 0; ti < mesh.triangle_count; ++ti) {
                const Triangle& tri = mesh.triangles[ti];

                // Retrieve triangle vertices
                Vec3 v0 = load_vec3(&mesh.vertices[tri.v0 * 3]);
                Vec3 v1 = load_vec3(&mesh.vertices[tri.v1 * 3]);
                Vec3 v2 = load_vec3(&mesh.vertices[tri.v2 * 3]);

                // Perform intersection test with the triangle
                float t;
                if (ray.intersect_triangle(v0, v1, v2, t) && t < closest_t) {
                    closest_t = t;
                    hit.t = t;
                    hit.normal = normalize(cross(v1 - v0, v2 - v0));
                    hit.material_id = tri.material_id;
                    any_hit = true;
                }
            }
        }

        return any_hit;
    }

} // namespace vkcut
