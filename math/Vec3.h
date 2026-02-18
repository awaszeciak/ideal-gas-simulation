#pragma once
#include <ostream>

/**
 * @brief 3D vector class with basic vector operations.
 * 
 * Provides vector arithmetic, dot/cross products, normalization,
 * and comparison operations. Used throughout the simulation for 
 * positions and velocities.
 */
class Vector3d{
public:
    
    Vector3d()=default;
    Vector3d(double x, double y, double z): _x(x), _y(y), _z(z) {}

    /// @brief Cross product of two vectors. 
    Vector3d cross(const Vector3d &other) const;

    /// @brief Dot product of two vectors. 
    double dot(const Vector3d &other) const;

    /// @brief Euclidean length of the vector.
    double magnitude() const;

    /// @brief Returns a unit vector in the same direction.
    Vector3d normalize() const;

    // Getters
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setters
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    //Operators
    Vector3d operator+(const Vector3d& other) const;
    Vector3d operator-(const Vector3d& other) const;
    Vector3d operator*(double scalar) const;
    bool operator==(const Vector3d& other) const;

    Vector3d& operator+=(const Vector3d& other);
    Vector3d& operator-=(const Vector3d& other);
    Vector3d& operator*=(double scalar);

    /// @brief Output vector to stream in format (x, y, z).
    friend std::ostream& operator<<(std::ostream& os, const Vector3d& v);

    
private:
    double _x=0;
    double _y=0;
    double _z=0;
    
};