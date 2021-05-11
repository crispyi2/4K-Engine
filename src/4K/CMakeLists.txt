include(hello_imgui_add_app)
file(COPY imconfig.h DESTINATION ./)
file(COPY run.sh DESTINATION ../../)
hello_imgui_add_app(4K main.cpp)