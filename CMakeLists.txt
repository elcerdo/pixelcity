project(pixelcity)
cmake_minimum_required(VERSION 2.6)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(pc ${SRCS})
target_link_libraries(pc ${OPENGL_gl_LIBRARY} ${SDL_LIBRARY})
