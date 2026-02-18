#pragma once
#include <GL/glut.h>
#include <string>
#include <vector>
#include "../world/World.h"
#include "../core/Particle.h"


/**
 * @brief Handles 3D visualization using OpenGL
 * 
 * The Renderer is responsible for: creating and managing the OpenGL window,
 * Rendering particles with velocity-based colors, drawing
 * the container box, displaying real-time statistics (FPS, temperature, pressure, etc.),
 * camera control (mouse rotation, zoom)
 */
class Renderer {
    private:
      // Window properties
      int _windowWidth;
      int _windowHeight;
      std::string _windowTitle;

      // Camera control
      float _cameraRotX, _cameraRotY;
      float _cameraDist;
      int _lastMouseX, _lastMouseY;
      bool _mousePressed;

      // World connection
      World* _worldPtr;    ///< Pointer to the simulation world (not owned)

      // Performance metrics
      int _frameCount;
      float _fps;
      double _lastTime;



    public:


        Renderer();
        ~Renderer();

        /// @brief Initializes OpenGL and creates the window. 
        bool initialize(int width, int height, std::string title);

        /// @brief Connects renderer to the simulation world.
        inline void setWorld(World* world) { _worldPtr = world; }    
        
        // Callbacks
        void update();
        void mouseButton(int button, int state, int x, int y);
        void mouseMove(int x, int y);
        void keyboard(unsigned char key, int x, int y);
        void reshape(int width, int height);

        // Rendering methods
        void render();
        void drawBox();
        void drawParticles();
        void drawInfo();

        // Static callbacks for GLUT
        static void displayCallback();
        static void keyboardCallback(unsigned char key, int x, int y);
        static void mouseCallback(int button, int state, int x, int y);
        static void motionCallback(int x, int y);
        static void reshapeCallback(int width, int height);
        static void idleCallback();
};