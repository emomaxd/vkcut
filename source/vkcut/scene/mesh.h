#pragma once

#include <cstddef>
#include <cstdint>

namespace vkcut {

struct Triangle {
    uint32_t v0, v1, v2;        // vertex indices
    uint32_t material_id;
};

struct Mesh {
    float* vertices;            // packed: x0,y0,z0, x1,y1,z1, ...
    Triangle* triangles;
    size_t vertex_count;
    size_t triangle_count;
};

} // namespace vkcut
