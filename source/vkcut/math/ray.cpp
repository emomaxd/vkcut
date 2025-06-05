#include <cmath>

#include "ray.h"

namespace vkcut {

    bool Ray::intersect_triangle(const Vec3& v0, const Vec3& v1, const Vec3& v2, float& out_t) const {
        constexpr float EPSILON = 1e-8f;

        // Triangle edges
        const Vec3 edge1 = v1 - v0;
        const Vec3 edge2 = v2 - v0;

        // Compute determinant
        const Vec3 pvec = cross(direction, edge2);
        const float det = dot(edge1, pvec);

        // Ray is parallel to triangle
        if (std::fabs(det) < EPSILON)
            return false;

        const float invDet = 1.0f / det;

        // Vector from v0 to ray origin
        const Vec3 tvec = origin - v0;

        // Compute U parameter
        const float u = dot(tvec, pvec) * invDet;
        if (u < 0.0f || u > 1.0f)
            return false;

        // Compute V parameter
        const Vec3 qvec = cross(tvec, edge1);
        const float v = dot(direction, qvec) * invDet;
        if (v < 0.0f || (u + v) > 1.0f)
            return false;

        // Compute t to intersection point
        const float t = dot(edge2, qvec) * invDet;
        if (t < EPSILON)
            return false;

        out_t = t;
        return true;
    }

    Ray generate_primary_ray(int x, int y, int width, int height, const Camera& cam) {
        float u = (x + 0.5f) / float(width);
        float v = (y + 0.5f) / float(height);

        float ndc_x = 2.0f * u - 1.0f;
        float ndc_y = 1.0f - 2.0f * v;

        float aspect = float(width) / float(height);
        float fov_scale = tanf(0.5f * cam.fov_rad);

        float px = ndc_x * aspect * fov_scale;
        float py = ndc_y * fov_scale;

        Vec3 dir = normalize(px * cam.right + py * cam.up - cam.forward);

        return Ray{ cam.position, dir };
    }
}
