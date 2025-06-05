#pragma once

#include <cmath>
#include <cstddef>
#include <limits>

namespace vkcut {

class Vec3 {
public:
    float X, Y, Z;

    inline constexpr Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f) noexcept
        : X(x), Y(y), Z(z) {}

    inline constexpr Vec3(const Vec3& other) noexcept = default;
    inline Vec3& operator=(const Vec3& other) noexcept = default;

    // Unary
    inline constexpr Vec3 operator-() const noexcept {
        return Vec3{-X, -Y, -Z};
    }

    // Binary
    inline constexpr Vec3 operator+(const Vec3& other) const noexcept {
        return Vec3{X + other.X, Y + other.Y, Z + other.Z};
    }

    inline constexpr Vec3 operator-(const Vec3& other) const noexcept {
        return Vec3{X - other.X, Y - other.Y, Z - other.Z};
    }

    inline constexpr Vec3 operator*(float scalar) const noexcept {
        return Vec3{X * scalar, Y * scalar, Z * scalar};
    }

    inline Vec3 operator/(float scalar) const noexcept {
        float inv = 1.0f / scalar;
        return Vec3{X * inv, Y * inv, Z * inv};
    }

    // Compound
    inline Vec3& operator+=(const Vec3& other) noexcept {
        X += other.X; Y += other.Y; Z += other.Z;
        return *this;
    }

    inline Vec3& operator-=(const Vec3& other) noexcept {
        X -= other.X; Y -= other.Y; Z -= other.Z;
        return *this;
    }

    inline Vec3& operator*=(float scalar) noexcept {
        X *= scalar; Y *= scalar; Z *= scalar;
        return *this;
    }

    inline Vec3& operator/=(float scalar) noexcept {
        float inv = 1.0f / scalar;
        X *= inv; Y *= inv; Z *= inv;
        return *this;
    }

    // Comparison
    inline constexpr bool operator==(const Vec3& other) const noexcept {
        return X == other.X && Y == other.Y && Z == other.Z;
    }

    inline constexpr bool operator!=(const Vec3& other) const noexcept {
        return !(*this == other);
    }

    // Length and normalization
    [[nodiscard]] inline float length() const noexcept {
        return std::sqrt(X * X + Y * Y + Z * Z);
    }

    [[nodiscard]] inline Vec3 normalized() const noexcept {
        float len = length();
        if (len > std::numeric_limits<float>::epsilon()) {
            float inv = 1.0f / len;
            return Vec3{X * inv, Y * inv, Z * inv};
        }
        return Vec3{};
    }

    inline void normalize() noexcept {
        float len = length();
        if (len > std::numeric_limits<float>::epsilon()) {
            float inv = 1.0f / len;
            X *= inv; Y *= inv; Z *= inv;
        }
    }
};

// Free operators

    inline constexpr Vec3 operator*(float scalar, const Vec3& v) noexcept {
        return v * scalar;
    }

    // Caution: this is mathematically ambiguous; rarely used.
    inline Vec3 operator/(float scalar, const Vec3& v) noexcept {
        return Vec3{scalar / v.X, scalar / v.Y, scalar / v.Z};
    }

    // Dot product
    inline constexpr float dot(const Vec3& a, const Vec3& b) noexcept {
        return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
    }

    // Cross product
    inline constexpr Vec3 cross(const Vec3& a, const Vec3& b) noexcept {
        return Vec3{
            a.Y * b.Z - a.Z * b.Y,
            a.Z * b.X - a.X * b.Z,
            a.X * b.Y - a.Y * b.X
        };
    }

    inline Vec3 normalize(const Vec3& v) noexcept {
        float len = v.length();
        if (len > std::numeric_limits<float>::epsilon()) {
            float inv = 1.0f / len;
            Vec3 result{v.X * inv, v.Y * inv, v.Z * inv};
            return result;
        }
        return Vec3{};
    }
} // namespace vkcut
