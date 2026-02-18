#include "../core/Particle.h"
#include "../systems/PhysicsSystem.h"
#include "../math/Vec3.h"
#include <iostream>
#include <iomanip>
#include <vector>

void printParticles(const std::vector<Particle>& particles, double time) {
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Times: " << time << " | ";
    
    for (size_t i = 0; i < particles.size(); i++) {
        Vector3d pos = particles[i].getPosition();
        Vector3d vel = particles[i].getVelocity();
        double speed = vel.magnitude();
        std::cout << "Particle " << i << ": pos(" 
                  << std::setw(6) << pos.getX() << ","
                  << std::setw(6) << pos.getY() << ","
                  << std::setw(6) << pos.getZ() << ") | vel("
                  << std::setw(6) << vel.getX() << ","
                  << std::setw(6) << vel.getY() << ","
                  << std::setw(6) << vel.getZ() << ") | speed: "
                  << std::setw(6) << speed << " | ";
    }
    std::cout << std::endl;
}

int main() {

    // Particle 0: 
    Vector3d pos0(-2.0, 0, 0);
    Vector3d vel0(1.0, 0, 0);
    Particle p0(pos0, vel0, 1.0, 1.0);  
    
    // Particle 1: 
    Vector3d pos1(2.0, 0, 0);
    Vector3d vel1(-1.0, 0, 0);
    Particle p1(pos1, vel1, 1.0, 1.0);  
    
    std::vector<Particle> particles = {p0, p1};
    
    
    double boxSize = 10.0;
    PhysicsSystem physics(boxSize);
    
    
    double dt = 0.1;
    int steps = 50;
    
    std::cout << "\n=== SIMULATION COLLISIONS ===\n";
    
    for (int i = 0; i < steps; i++) {
        double time = i * dt;
        printParticles(particles, time);
        
       
        physics.update(particles, dt);
        
       
        Vector3d delta = particles[0].getPosition() - particles[1].getPosition();
        double dist = delta.magnitude();
        
        if (dist < 2.0) { 
            std::cout << "Particles are colliding ! Distance: " << dist << std::endl;
        }
    }
    
    
    double energy0 = 0.5 * particles[0].getMass() * 
                     particles[0].getVelocity().magnitude() *
                     particles[0].getVelocity().magnitude();
    double energy1 = 0.5 * particles[1].getMass() * 
                     particles[1].getVelocity().magnitude() *
                     particles[1].getVelocity().magnitude();
    
    std::cout << "\n=== ENERGY AFTER COLLISION ===\n";
    std::cout << "Particle's 0 energy: " << energy0 << std::endl;
    std::cout << "Particle's 1 energy: " << energy1 << std::endl;
    std::cout << "Sum of energy: " << (energy0 + energy1) << std::endl;
    
    return 0;
}