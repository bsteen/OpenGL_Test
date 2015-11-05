#define GLEW_STATIC
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <iostream>

int main(){
    //Initiliaze window setting values
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    //settings.antialiasingLevel = 2; // Optional

    //Create window
    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Close, settings);


    glewExperimental = GL_TRUE;
    glewInit();

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    //Is the vertexBuffer succesfully created?
    std::cout << vertexBuffer << std::endl;

    //Run main window loop
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
