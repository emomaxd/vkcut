#pragma once

#include <cmath>    // std::sqrt
#include <cstddef>  // std::size_t
#include <limits>   // std::numeric_limits

namespace vkcut {

class Vec2 {
public:
    float X, Y;

    inline constexpr Vec2(float x = 0.0f, float y = 0.0f) noexcept : X(x), Y(y) {}
    inline constexpr Vec2(const Vec2& other) noexcept = default;

    inline Vec2& operator=(const Vec2& other) noexcept = default;

    inline constexpr Vec2 operator+(const Vec2& other) const noexcept {
        return Vec2{X + other.X, Y + other.Y};
    }

    inline constexpr Vec2 operator-(const Vec2& other) const noexcept {
        return Vec2{X - other.X, Y - other.Y};
    }

    inline constexpr Vec2 operator*(float scalar) const noexcept {
        return Vec2{X * scalar, Y * scalar};
    }

    inline Vec2 operator/(float scalar) const noexcept {
        float inv = 1.0f / scalar;
        return Vec2{X * inv, Y * inv};
    }

    inline Vec2& operator+=(const Vec2& other) noexcept {
        X += other.X; Y += other.Y;
        return *this;
    }

    inline Vec2& operator-=(const Vec2& other) noexcept {
        X -= other.X; Y -= other.Y;
        return *this;
    }

    inline Vec2& operator*=(float scalar) noexcept {
        X *= scalar; Y *= scalar;
        return *this;
    }

    inline Vec2& operator/=(float scalar) noexcept {
        float inv = 1.0f / scalar;
        X *= inv; Y *= inv;
        return *this;
    }

    inline constexpr bool operator==(const Vec2& other) const noexcept {
        return X == other.X && Y == other.Y;
    }

    inline constexpr bool operator!=(const Vec2& other) const noexcept {
        return !(*this == other);
    }

    inline constexpr Vec2 operator-() const noexcept {
        return Vec2{-X, -Y};
    }

    [[nodiscard]] inline float length() const noexcept {
        return std::sqrt(X * X + Y * Y);
    }

    [[nodiscard]] inline Vec2 normalized() const noexcept {
        float len = length();
        if (len > std::numeric_limits<float>::epsilon()) {
            float inv = 1.0f / len;
            return Vec2{X * inv, Y * inv};
        }
        return *this;
    }

    inline void normalize() noexcept {
        float len = length();
        if (len > std::numeric_limits<float>::epsilon()) {
            float inv = 1.0f / len;
            X *= inv; Y *= inv;
        }
    }
};

// Free operators and functions

inline constexpr Vec2 operator*(float scalar, const Vec2& v) noexcept {
    return v * scalar;
}

// Usually undefined behavior unless well-justified.
// Optional: comment or remove if not mathematically needed.
inline Vec2 operator/(float scalar, const Vec2& v) noexcept {
    return Vec2{scalar / v.X, scalar / v.Y};
}

inline constexpr float dot(const Vec2& a, const Vec2& b) noexcept {
    return a.X * b.X + a.Y * b.Y;
}

} // namespace vkcut
