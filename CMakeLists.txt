cmake_minimum_required(VERSION 3.28)
project(Framer)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/stb)

set(CMAKE_CXX_STANDARD 23)

add_library(Framer)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.cpp")

target_compile_definitions(Framer PUBLIC GLFW_INCLUDE_NONE=1)

target_sources(Framer PRIVATE ${MY_SOURCES} )
target_include_directories(Framer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/Framer")

target_link_libraries(Framer PUBLIC glad glfw glm stb)