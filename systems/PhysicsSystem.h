#pragma once
#include <cmath>
#include "../math/Vec3.h"
#include "../core/Particle.h"
#include <string>
#include <vector>

class PhysicsSystemTest;

/**
 * @brief Handles all physics calculations for particle motion.
 * 
 * Responsible for: time integration (Euler method), elastic 
 * collisions between particles, wall collisions with box boundaries,
 * color updates based on velocity.
 */
class PhysicsSystem{
public:
    /// @brief Constructor with given box size. 
    PhysicsSystem(double boxSize);

    /// @brief  Main update loop - integrates motion and handles collisions.
    void update(std::vector<Particle>& particles, double dt);

    friend class PhysicsSystemTest;

private:
    void applyForces(std::vector<Particle>& particles);

    /// @brief Detects and resolves elastic collisions between particles. 
    void handleParticleCollisions(std::vector<Particle>& particles);

    /// @brief Handles particle collisions with container walls.
    void handleWallCollisions(std::vector<Particle>& particles);

    /// @brief Updates particle position using Euler integration. 
    void integrate(Particle& p, double dt);

    /// @brief Updates particle color based on its current speed.
    void updateColorFromVelocity(Particle& particle);

    double _halfSize;    ///< Half of the box size (for boundary checks)

};
