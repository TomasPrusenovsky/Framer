cmake_minimum_required(VERSION 3.28)
project(Framer)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)

set(CMAKE_CXX_STANDARD 23)

add_library(Framer)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

target_compile_definitions(Framer PRIVATE GLFW_INCLUDE_NONE=1)

target_sources(Framer PRIVATE ${MY_SOURCES} )
target_include_directories(Framer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(Framer PRIVATE glad glfw)