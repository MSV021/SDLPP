#ifndef POINT_H
#define POINT_H

#include <cmath> 

namespace SDLPP {
    /**
     * Represents a 2D vector or point.
    */
    class Vector { 
    public: 
        Vector() : x{0}, y{0} {} 
        Vector(double x, double y) : x{x}, y{y} {}; 

        /**
         * Normalizes this vector, keeping the direction but changing its magnitude to one.
        */
        void Normalize(void);
        
        Vector operator-(const Vector&) const; 
        Vector operator+(const Vector&) const; 
        Vector operator*(double) const; 
        Vector operator/(double) const;
        Vector& operator-=(const Vector&);
        Vector& operator+=(const Vector&); 
        Vector& operator*=(double);
        Vector& operator/=(double);
        bool operator==(const Vector&) const;
        
        const static Vector up; 
        const static Vector down; 
        const static Vector left; 
        const static Vector right; 
        const static Vector one;
        const static Vector zero;
        
        /**
         * Returns this vector's magnitude.
        */
        constexpr double magnitude() const { return std::sqrt(x*x + y*y); }
        /**
         * Returns normalized version of this vector, keeping the direction but changing its magnitude to one.
         * Note that this does not change this vector but returns a new one.
         * If you want to normalize this vector call Normalize().
        */
        Vector normalized() const { return Vector(x/magnitude(), y/magnitude()); }
        double x, y; 
    }; 
}

#endif