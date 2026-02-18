#include "../world/World.h"
#include <iostream>
#include <ctime>

int main() {
    srand(time(nullptr));
    World world;

    world.initializeRandom(30, 5.0);
    
    std::cout << "=== STATISTICS ===" << std::endl;
    std::cout << "Particles: " << world.getParticles().size() << std::endl;
    std::cout << "Energy: " << world.getTotalEnergy() << std::endl;
    std::cout << "Temperature: " << world.getTemperature() << std::endl;
    std::cout << "Pressure: " << world.getPressure() << std::endl;
    
    return 0;
}