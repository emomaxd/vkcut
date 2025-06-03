#pragma once

#include <cmath>
#include <cstddef>

namespace vkcut {

class Vec3 {
public:
    float X, Y, Z;

    Vec3(float x = 0, float y = 0, float z = 0) : X(x), Y(y), Z(z) {}
    Vec3(const Vec3& other) : X(other.X), Y(other.Y), Z(other.Z) {}

    Vec3& operator=(const Vec3& other) {
        X = other.X; Y = other.Y; Z = other.Z;
        return *this;
    }

    Vec3 operator+(const Vec3& other) const {
        return Vec3{X + other.X, Y + other.Y, Z + other.Z};
    }

    Vec3 operator-(const Vec3& other) const {
        return Vec3{X - other.X, Y - other.Y, Z - other.Z};
    }

    Vec3 operator*(float scalar) const {
        return Vec3{X * scalar, Y * scalar, Z * scalar};
    }

    Vec3 operator/(float scalar) const {
        float inv = 1.0f / scalar;
        return Vec3{X * inv, Y * inv, Z * inv};
    }

    Vec3& operator+=(const Vec3& other) {
        X += other.X; Y += other.Y; Z += other.Z;
        return *this;
    }

    Vec3& operator-=(const Vec3& other) {
        X -= other.X; Y -= other.Y; Z -= other.Z;
        return *this;
    }

    Vec3& operator*=(float scalar) {
        X *= scalar; Y *= scalar; Z *= scalar;
        return *this;
    }

    Vec3& operator/=(float scalar) {
        float inv = 1.0f / scalar;
        X *= inv; Y *= inv; Z *= inv;
        return *this;
    }

    bool operator==(const Vec3& other) const {
        return X == other.X && Y == other.Y && Z == other.Z;
    }

    bool operator!=(const Vec3& other) const {
        return !(*this == other);
    }

    Vec3 operator-() const {
        return Vec3{-X, -Y, -Z};
    }

    float length() const {
        return std::sqrt(X * X + Y * Y + Z * Z);
    }

    Vec3 normalize() const {
        float len = length();
        if (len <= 0) {
            return Vec3{0};
        }
        return *this / len;
    }
};

inline Vec3 operator*(float scalar, const Vec3& v) {
    return v * scalar;
}

inline Vec3 operator/(float scalar, const Vec3& v) {
    return Vec3{scalar / v.X, scalar / v.Y, scalar / v.Z};
}

inline float dot(const Vec3& a, const Vec3& b) {
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}

inline Vec3 cross(const Vec3& a, const Vec3& b) {
    return Vec3{
        a.Y * b.Z - a.Z * b.Y,
        a.Z * b.X - a.X * b.Z,
        a.X * b.Y - a.Y * b.X
    };
}

} // namespace vkcut
