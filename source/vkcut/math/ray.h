#pragma once

#include "vec3.h"

namespace vkcut {

    struct Ray {
        Vec3 origin;
        Vec3 direction;
   
        Ray() = default;

        bool intersect_triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, float& t) const;

        bool intersect_sphere(const Vec3& center, float radius, float& t) const;
    };
} // namespace vkcut
