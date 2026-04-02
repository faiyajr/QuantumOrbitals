cmake_minimum_required(VERSION 3.10)
project(AtomSim)

set(CMAKE_CXX_STANDARD 17)

# Find packages
find_package(OpenGL REQUIRED)

# Set paths to your libraries (change these to where you installed them)
set(GLFW_DIR "C:/path/to/glfw")
set(GLEW_DIR "C:/path/to/glew")
set(GLM_DIR "C:/path/to/glm")

include_directories(
    ${GLFW_DIR}/include
    ${GLEW_DIR}/include
    ${GLM_DIR}
)

link_directories(
    ${GLFW_DIR}/lib-vc2022
    ${GLEW_DIR}/lib/Release/x64
)

add_executable(AtomSim src/atom.cpp)

target_link_libraries(AtomSim
    GL
    glfw
    GLEW
)