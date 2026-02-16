#include <iostream>
#include "Renderer.h"

Renderer* Renderer::instanca = nullptr;


Renderer::Renderer() :
    windowWidth(1024), windowHeight(768), windowTitle("Ideal Gas Simulation 3D"),
    cameraRotX(30.0), cameraRotY(-30.0), cameraDist(15.0), lastMouseX(0), lastMouseY(0),
    mousePressed(false), boxSize(10.0), frameCount(0), fps(0.0), lastTime(0.0) {
    
    instance = this;
}

bool Renderer::initialize(int width, int height, std::string title) {
    windowHeight = height;
    windowTitle = title;
    windowWidth = width;

    int argc = 1;
    char* argv[1] = {(char*)"simulation"};
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(windowTitle.c_str());
    

}

Renderer::~Renderer() {
    instance = nullptr;
}