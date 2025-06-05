#pragma once

#include "math/vec3.h"
#include "renderer/camera.h"

namespace vkcut {

    struct Ray {
        Vec3 origin;
        Vec3 direction;
   
        bool intersect_triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, float& t) const;
    };


    Ray generate_primary_ray(int x, int y, int width, int height, const Camera& cam);

} // namespace vkcut
