#include "Vector.h"

const SDLPP::Vector SDLPP::Vector::up = SDLPP::Vector(0, -1); 
const SDLPP::Vector SDLPP::Vector::down = SDLPP::Vector(0, 1); 
const SDLPP::Vector SDLPP::Vector::left = SDLPP::Vector(-1, 0); 
const SDLPP::Vector SDLPP::Vector::right = SDLPP::Vector(1, 0); 
const SDLPP::Vector SDLPP::Vector::one = SDLPP::Vector(1, 1); 
const SDLPP::Vector SDLPP::Vector::zero = SDLPP::Vector(0, 0); 

void SDLPP::Vector::Normalize() {
    double mag = magnitude(); 
    x /= mag; 
    y /= mag;
}

SDLPP::Vector SDLPP::Vector::operator-(const Vector& other) const {
    return SDLPP::Vector(this->x - other.x, this->y - other.y); 
} 

SDLPP::Vector SDLPP::Vector::operator+(const Vector& other) const {
    return SDLPP::Vector(this->x + other.x, this->y + other.y); 
} 

SDLPP::Vector SDLPP::Vector::operator*(double value) const {
    return SDLPP::Vector(this->x * value, this->y * value); 
} 

SDLPP::Vector SDLPP::Vector::operator/(double value) const {
    return SDLPP::Vector(this->x / value, this->y / value); 
}

SDLPP::Vector& SDLPP::Vector::operator-=(const Vector& other) {
    *this = *this - other;
    return *this;
}

SDLPP::Vector& SDLPP::Vector::operator+=(const Vector& other) {
    *this = *this + other;
    return *this;
}

SDLPP::Vector& SDLPP::Vector::operator*=(double value) {
    *this = *this * value;
    return *this;
}

SDLPP::Vector& SDLPP::Vector::operator/=(double value) {
    *this = *this / value;
    return *this;
}

bool SDLPP::Vector::operator==(const Vector& other) const {
    return (this->x == other.x) && (this->y == other.y);
}