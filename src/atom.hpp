#include <GLFW/glfw3.h> // window, input, callbacks
#include <GL/glew.h> // gl*, GLuint, shaders, buffers
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