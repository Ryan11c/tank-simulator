#pragma once
#include <cmath>

class Vector2D {
public:
    Vector2D(float setX, float setY);
    Vector2D(const Vector2D& other);
    Vector2D(float angleRad);
    Vector2D();

    float angle();

    float magnitude();
    Vector2D normalize();
    Vector2D computeNormal();
    Vector2D computeNegativeReciprocal();

    float dot(const Vector2D& other);
    float cross(const Vector2D& other);
    float angleBetween(const Vector2D& other);

    Vector2D operator+(const float amount);
    Vector2D operator-(const float amount);
    Vector2D operator*(const float amount);
    Vector2D operator/(const float amount);

    Vector2D operator+(const Vector2D& other);
    Vector2D operator-(const Vector2D& other);
    Vector2D operator*(const Vector2D& other);
    Vector2D operator/(const Vector2D& other);

    Vector2D& operator+=(const float amount);
    Vector2D& operator-=(const float amount);
    Vector2D& operator*=(const float amount);
    Vector2D& operator/=(const float amount);

    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator*=(const Vector2D& other);
    Vector2D& operator/=(const Vector2D& other);

    float x, y;
};
