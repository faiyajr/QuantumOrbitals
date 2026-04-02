#include <GL/glew.h> // gl*, GLuint, shaders, buffers
#include <GLFW/glfw3.h> // window, input, callbacks
#include <glm/glm.hpp> // vec3, vec4, mat4
#include <glm/gtc/matrix_transform.hpp> // perspective, lookAt, translate, scale, radians
#include <glm/gtc/type_ptr.hpp> // value_ptr for opengl to point to raw memory instead of objects (opengl is in c)
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace glm;
using namespace std;

struct Particle {
    vec2 position;
    int charge;
    Particle(vec2 position, int charge) : position(position), charge(charge) {}
};

struct Engine {
    //
    GLFWwindow* window;
    int WIDTH = 800;
    int HEIGHT = 600;
    int frame_buffer_width;
    int frame_buffer_height;

    Engine(){
        // glfw init
        if(!glfwInit()){
            cerr << "Failed to initialize glfw" << endl;
            exit(EXIT_FAILURE);
        }
        // creating window
        window = glfwCreateWindow(WIDTH, HEIGHT, "atom sim by fahhhhaj", nullptr, nullptr);
        if (!window){
            cerr << "Failed to create window" << endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(window);
        // for retina displays
        glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);
        glViewport(0, 0, frame_buffer_width, frame_buffer_height);
    }

    void engine_run(){
        // clear and projection view to set up coordinate system
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION); 
        glLoadIdentity();
        // set coordinate system to (0,0) center
        GLdouble half_width = frame_buffer_width / 2.0f;
        GLdouble half_height = frame_buffer_height / 2.0f;
        glOrtho(-half_width, half_width, -half_height, half_height, -1.0, 1.0);
        // go to modelview to draw
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
};
// create engine
Engine engine;

// main
int main(){
    while(!glfwWindowShouldClose(engine.window)){
        glfwSwapBuffers(engine.window);
        glfwPollEvents();
    }
}

               

