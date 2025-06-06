#pragma once

#include "math/vec3.h"

namespace vkcut {
    struct Camera {
        Vec3 position;
        Vec3 forward;
        Vec3 right;
        Vec3 up;
        float fov_rad;

        Camera() = default;
    };
}
