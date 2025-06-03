#pragma once

#include "vec3.h"

namespace vkcut {

    struct Ray {
        vec3 origin;
        vec3 direction;
   
        Ray() = default;

        bool intersect_triangle(const vec3& v0, const vec3& v1, const vec3& v2, float& t) const;

        bool intersect_sphere(const vec3& center, float radius, float& t) const;
    }
} // namespace vkcut
