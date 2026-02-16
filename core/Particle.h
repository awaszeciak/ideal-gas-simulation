#pragma once
#include <cmath>
#include "../math/Vec3.h"
#include <string>

class Particle{
public:







private:

Vector3d _position;
Vector3d _velocity;
Vector3d _acceleration;
Vector3d _spin;
Vector3d _color;

double _mass;
double _ratio;

int _degreesOfFreedom;

std::string _type;


};