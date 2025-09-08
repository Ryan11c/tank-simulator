#include "Vector2D.h"

Vector2D::Vector2D(float setX, float setY) : x(setX), y(setY) {}
Vector2D::Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}
Vector2D::Vector2D(float angleRad) : x(std::cos(angleRad)), y(std::sin(angleRad)) {}
Vector2D::Vector2D() : x(0.0f), y(0.0f) {}

float Vector2D::angle() { return std::atan2(y, x); }

float Vector2D::magnitude() { return std::sqrt(x * x + y * y); }

Vector2D Vector2D::normalize() {
    float magnitudeStored = magnitude();
    if (magnitudeStored > 0.0f) {
        x /= magnitudeStored;
        y /= magnitudeStored;
    }
    return *this;
}

Vector2D Vector2D::computeNormal() { return Vector2D(*this).normalize(); }
Vector2D Vector2D::computeNegativeReciprocal() { return Vector2D(-y, x); }

float Vector2D::dot(const Vector2D& other) { return x * other.x + y * other.y; }
float Vector2D::cross(const Vector2D& other) { return x * other.y - y * other.x; }
float Vector2D::angleBetween(const Vector2D& other) { return std::atan2(cross(other), dot(other)); }

Vector2D Vector2D::operator+(const float amount) { return Vector2D(x + amount, y + amount); }
Vector2D Vector2D::operator-(const float amount) { return Vector2D(x - amount, y - amount); }
Vector2D Vector2D::operator*(const float amount) { return Vector2D(x * amount, y * amount); }
Vector2D Vector2D::operator/(const float amount) { return Vector2D(x / amount, y / amount); }

Vector2D Vector2D::operator+(const Vector2D& other) { return Vector2D(x + other.x, y + other.y); }
Vector2D Vector2D::operator-(const Vector2D& other) { return Vector2D(x - other.x, y - other.y); }
Vector2D Vector2D::operator*(const Vector2D& other) { return Vector2D(x * other.x, y * other.y); }
Vector2D Vector2D::operator/(const Vector2D& other) { return Vector2D(x / other.x, y / other.y); }

Vector2D& Vector2D::operator+=(const float amount) { x += amount; y += amount; return *this; }
Vector2D& Vector2D::operator-=(const float amount) { x -= amount; y -= amount; return *this; }
Vector2D& Vector2D::operator*=(const float amount) { x *= amount; y *= amount; return *this; }
Vector2D& Vector2D::operator/=(const float amount) { x /= amount; y /= amount; return *this; }

Vector2D& Vector2D::operator+=(const Vector2D& other) { x += other.x; y += other.y; return *this; }
Vector2D& Vector2D::operator-=(const Vector2D& other) { x -= other.x; y -= other.y; return *this; }
Vector2D& Vector2D::operator*=(const Vector2D& other) { x *= other.x; y *= other.y; return *this; }
Vector2D& Vector2D::operator/=(const Vector2D& other) { x /= other.x; y /= other.y; return *this; }
