/* Copyright 2012 The Emscripten Authors.  All rights reserved.
   Emscripten is available under two separate licenses, the MIT license and the
   University of Illinois/NCSA Open Source License.  Both these licenses can be
   found in the LICENSE file. 
*/

// Application

// Importing

#include <stdio.h>

#include <SDL2/SDL.h>

#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <vector>

// Custom Shell

#include <emscripten/emscripten.h>
#include <emscripten/html5.h>

GLFWwindow* window = nullptr;
float red = 0.0;

// Epic

void mainLoop() {
    // Clear the screen with a color
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap the buffers of the window
    glfwSwapBuffers(window);

    // Poll for the events
    glfwPollEvents();
}

int main() {

  // Init WebGL

  std::cout << "Starting" << std::endl;

    // Initialize glfw
    if (!glfwInit())
        exit(EXIT_FAILURE);

    // Create the window
    window = glfwCreateWindow(640, 480, "Emscripten webgl example", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // Make this window the current context
    glfwMakeContextCurrent(window);

    std::cout << "Going into loop" << std::endl;
#ifdef EMSCRIPTEN
    // Define a mail loop function, that will be called as fast as possible
    emscripten_set_main_loop(&mainLoop, 0, 1);
#else
    // This is the normal C/C++ main loop
    while (!glfwWindowShouldClose(window)) {
        mainLoop();
    }
#endif

    // Tear down the system
    std::cout << "Loop ended" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;

  /* Console Shit */

  printf("hello, world!\n");

  FILE *version = fopen("assets/returns/Version.txt", "rb");
  if (!version) {
    printf("cannot open file\n");
    return 1;
  }
  while (!feof(version)) {
    char c = fgetc(version);
    if (c != EOF) {
      putchar(c);
    }
  }
  fclose (version);

  /* Title Screen */

  FILE * logo = fopen("assets/images/logo.png", "r");



  return 0;
}
