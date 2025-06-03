#pragma once

#include <cstddef>

namespace vkcut {

class Vec2 {
public:
    float X, Y;

     Vec2(float x = 0, real_t y = 0) : X(x), Y(y) {}
     Vec2(const Vec2& other) : X(other.X), Y(other.Y) {}

    Vec2& operator=(const Vec2& other) {
        X = other.X; Y = other.Y;
        return *this;
    }

     Vec2 operator+(const Vec2& other) const {
        return Vec2{X + other.X, Y + other.Y};
    }

     Vec2 operator-(const Vec2& other) const {
        return Vec2{X - other.X, Y - other.Y};
    }

     Vec2 operator*(float scalar) const {
        return Vec2{X * scalar, Y * scalar};
    }

     Vec2 operator/(float scalar) const {
        float inv = 1.0f / scalar;
        return Vec2{X * inv, Y * inv};
    }

     Vec2& operator+=(const Vec2& other) {
        X += other.X; Y += other.Y;
        return *this;
    }

     Vec2& operator-=(const Vec2& other) {
        X -= other.X; Y -= other.Y;
        return *this;
    }

     Vec2& operator*=(float scalar) {
        X *= scalar; Y *= scalar;
        return *this;
    }

     Vec2& operator/=(float scalar) {
        float inv = 1.0f / scalar;
        X *= inv; Y *= inv;
        return *this;
    }

     bool operator==(const Vec2& other) const {
        return X == other.X && Y == other.Y;
    }

     bool operator!=(const Vec2& other) const {
        return !(*this == other);
    }

     Vec2 operator-() const {
        return Vec2{-X, -Y};
    }

     float length() const {
        const float len = nyx::sqrt( X*X + Y*Y);
        return nyx::sqrt(len);
    }

     Vec2 normalized() const {
        float len = length();
        if (len > 0) {
            float inv = 1.0f / len;
            return Vec2{X * inv, Y * inv};
        }
        return *this;
    }

     void normalize() {
        float len = length();
        if (len > 0) {
            float inv = 1.0f / len;
            X *= inv; Y *= inv;
        }
    }
};

 Vec2 operator*(float scalar, const Vec2& v) {
    return v * scalar;
}

 Vec2 operator/(float scalar, const Vec2& v) {
    return Vec2{scalar / v.X, scalar / v.Y};
}

 float dot(const Vec2& a, const Vec2& b) {
    return a.X * b.X + a.Y * b.Y;
}

} // namespace vkcut
