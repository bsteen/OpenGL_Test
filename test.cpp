#define GLEW_STATIC
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <iostream>

//The code in this program comes from https://open.gl

int main(){
    //Initiliaze window setting values--------------
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    //settings.antialiasingLevel = 2; // Optional

    //Create window---------------------------------
    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Close, settings);

    glewExperimental = GL_TRUE;//Force GLEW to use a modern OpenGL method for checking if a function is available.
    glewInit();


    //Prepare to draw shape-------------------------
    float vertices[] = {
        0.0f,  0.5f, // Vertex 1 (X, Y)
        0.5f, -0.5f, // Vertex 2 (X, Y)
        -0.5f, -0.5f  // Vertex 3 (X, Y)
    };//A triangle.

    //Make buffer (Vertex Buffer Object, "vbo") to store data
    GLuint vbo; //GL unsigned int to store pointer of object.
    glGenBuffers(1, &vbo); //Generate 1 buffer

    //Make Vertex Buffer Object the active array buffer.
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Copy vertices to the active buffer.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //GL_STATIC_DRAW => The vertex data will be uploaded once and drawn many times
    //Determines in what kind of memory the data is stored on the graphics card for the highest efficiency.

    //Add vertex shaders

    //Run main window loop--------------------------
    bool running = true;
    while (running){
        sf::Event windowEvent;

        while (window.pollEvent(windowEvent)){

            switch (windowEvent.type){

                case sf::Event::Closed:
                    running = false;
                    break;
                case sf::Event::KeyPressed:
                    if (windowEvent.key.code == sf::Keyboard::Escape){
                        running = false;
                    }
                    break;
            }
        }
    }

    return 0;
}
