#include <cmath>

#include "ray.h"

bool Ray::intersect_triangle(const vec3& v0, const vec3& v1, const vec3& v2, float& t) const {
    const float EPSILON = 1e-8f;

    vec3 e1 = v1 - v0;
    vec3 e2 = v2 - v0;

    vec3 h = direction.cross(e2);
    float a = e1.dot(h);

    if (a > -EPSILON && a < EPSILON)
        return false;

    float f = 1.0f / a;
    vec3 s = origin - v0;
    float u = f * s.dot(h);

    if (u < 0.0f || u > 1.0f)
        return false;

    vec3 q = s.cross(e1);
    float v = f * direction.dot(q);

    if (v < 0.0f || u + v > 1.0f)
        return false;

    t = f * e2.dot(q);

    return t > EPSILON;
}

bool Ray::intersect_sphere(const vec3& center, float radius, float& t) const {
    vec3 oc = origin - center;
    float a = direction.dot(direction);
    float b = 2.0f * oc.dot(direction);
    float c = oc.dot(oc) - radius * radius;

    float discriminant = b * b - 4.0f * a * c;

    if (discriminant < 0.0f)
        return false;

    float sqrt_discriminant = std::sqrt(discriminant);
    float t0 = (-b - sqrt_discriminant) / (2.0f * a);
    float t1 = (-b + sqrt_discriminant) / (2.0f * a);

    if (t0 > 0.0f) {
        t = t0;
    } else if (t1 > 0.0f) {
        t = t1;
    } else {
        return false;
    }

    return true;
}
