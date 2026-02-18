#pragma once
#include <vector>
#include "../core/Particle.h"
#include "../core/PhysicsSystem.h"
#include "../math/Vec3.h"


/**
 * @brief Manages the simulation world and statistical data.
 * 
 * The World class is the central hub that: stores all particles,
 * initializes random particle positions and velocities, calculates
 * thermodynamic properties (temperature, pressure, energy), maintains 
 * velocity histogram for Maxwell-Boltzmann distribution, coordinates physics
 * updates through PhysicsSystem.
 */
class World {
    private:
        std::vector<Particle> _particles;   ///< All particles in the simulation
        float _boxSize;                 ///< Conatiner size (cube edge length)

        PhysicsSystem _physicsSystem;       ///< Physics engine

        // Statistical quantities
        double _totalEnergy;        ///< Total kinetic energy
        double _temperature;        ///< Temperature (in units where kB = 1)
        double _pressure;          ///< Pressure (P = nT/V)
        std::vector<int> _velocityHistogram;        ///< Speed distribution for histogram
    
    public:
        /// @brief Constructs world with default box size (10.0)
        World();

        /// @brief Initializes particles with random positions and velocities.
        /// @param numParticles Number of particles to create
        /// @param maxSpeed Maximum initial speed
        void initializeRandom(int numParticles, double maxSpeed);

        // Getters
        const std::vector<Particle>& getParticles() const {
            return _particles;
        }
        float getBoxSize() const { return _boxSize; }
        
        /// @brief Recalculates all statistical quantities based on current particle states.
        void calculateStatistics();

        // Statistical getters
        double getAverageSpeed() const;
        double getMaxSpeed() const;
        double getTemperature() const { return _temperature; }
        double getPressure() const { return _pressure; }
        double getTotalEnergy() const { return _totalEnergy; }
        const std::vector<int>& getHistogram() const { return _velocityHistogram; }

        /// @brief Performs one simulation step.
        /// @param dt Time step size
        void update(double dt);

};