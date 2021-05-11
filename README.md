# Minecraft-Purpur
An unofficial Mincraft engine powered by ImGui, Webassembly, Emscripten, and c++

## Building 

1. Add emsdk to your shell path;

You need to **source** the script ~/emsdk/emsdk_env.sh

````bash
source ~/emsdk/emsdk_env.sh
````

2. Run cmake, using "emcmake":

`````bash
mkdir build_emscripten
cd build_emscripten
emcmake cmake .. -DHELLOIMGUI_USE_SDL_OPENGL3=ON ..
`````

Note: the script [tools/emscripten/cmake_emscripten.sh](tools/emscripten/cmake_emscripten.sh) does the cmake part of this.

3. Build

````bash
make -j 4
````

4. Run

`````bash
npm i -g http-server
node ./run.js
`````

## Credits

- tools
  - Hello ImGui: https://github.com/pthom/hello_imgui | Used as a base for the ui