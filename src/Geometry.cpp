#include <cmath>

#include "Geometry.h"

Tuple::Tuple() : x(0), y(0), z(0), w(1) {};
Tuple::Tuple(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {};

Tuple Tuple::operator+(const Tuple& v) {
    return Tuple(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w);
}

Tuple Tuple::operator-(const Tuple& v) {
    return Tuple(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w);
}

Tuple Tuple::operator-() {
    return Tuple(-this->x, -this->y, -this->z, -this->w);
}

Tuple Tuple::operator*(const double& s) {
    return Tuple(this->x * s, this->y * s, this->z * s, this->w * s);
}

Tuple Tuple::operator/(const double& s) {
    return Tuple(this->x / s, this->y / s, this->z / s, this->w / s);
}

bool Tuple::operator==(const Tuple& v) {
    return (this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w);
}

double Tuple::magnitude() {
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2));
}

double Tuple::squareMagnitude() {
    return pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2);
}

Tuple Tuple::normalize() {
    double inverseSqrt =  fastInverseSqrt(this->squareMagnitude());
    return Tuple(
        this->x * inverseSqrt,
        this->y * inverseSqrt,
        this->z * inverseSqrt,
        this->w * inverseSqrt
    );
}

double Tuple::dot(const Tuple& v) {
    return this->x * v.x + this->y * v.y + this->z * v.z + this->w * v.w;
}

Tuple Tuple::cross(const Tuple& v) {
    return Tuple(
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z,
        this->x * v.y - this->y * v.x,
        0
    );
}
