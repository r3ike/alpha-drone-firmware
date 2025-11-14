#pragma once
#include <cmath>

struct Vector3f
{
    float x,y,z;


    Vector3f() : x(0),y(0),z(0) {}
    Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3f operator+(const Vector3f& v) const { return {x+v.x, y+v.y, z+v.z}; }
    Vector3f operator-(const Vector3f& v) const { return {x-v.x, y-v.y, z-v.z}; }
    Vector3f operator*(float s) const { return {x*s, y*s, z*s}; }
    Vector3f operator/(float s) const { return {x/s, y/s, z/s}; }

     // Prodotti
    float dot(const Vector3f& v) const { return x*v.x + y*v.y + z*v.z; }
    Vector3f cross(const Vector3f& v) const {
        return { y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x };
    }

    // Utility
    float norm() const { return std::sqrt(x*x + y*y + z*z); }
    void normalize() {
        float n = norm();
        if (n > 1e-6f) { x /= n; y /= n; z /= n; }
    }
};
