cmake_minimum_required(VERSION 3.12)
project(4K_Engine)

if("${CMAKE_SYSTEM}" MATCHES "Linux" OR "${CMAKE_SYSTEM}" MATCHES "Darwin-*")

    find_package(OpenGL REQUIRED)

    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(glfw-3.2.1)
endif()

include_directories(glfw-3.2.1/include)
set(CMAKE_CXX_STANDARD 17)

add_executable(4K_Engine src/Game.cpp)
target_link_libraries(4K_Engine glfw ${OPENGL_LIBRARIES})

if (DEFINED EMSCRIPTEN)
set_target_properties(4K_Engine
        PROPERTIES SUFFIX ".html"
        LINK_FLAGS " --preload-file assets --emrun --shell-file src/html/shell.html -o build/game.html -s USE_GLFW=3")
        set(EXECUTABLE_OUTPUT_PATH build)
endif (DEFINED EMSCRIPTEN)