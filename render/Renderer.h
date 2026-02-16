#pragma once
#include <GL/glut.h>
#include <string>
#include <vector>

class Renderer {
    private:
      int windowWidth;
      int windowHeight;
      std::string windowTitle;

      float cameraRotX, cameraRotY;
      float cameraDist;
      int lastMouseX, lastMouseY;
      bool mousePressed;

      std::vector<Particle> particles;
      float boxSize;

      int frameCount;
      float fps;
      double lastTime;


    public:
        Renderer();
        ~Renderer();

        bool initialize(int width, int height, std::string title);
}