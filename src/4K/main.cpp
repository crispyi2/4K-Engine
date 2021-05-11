#define IMGUI_USER_CONFIG "imconfig.h"

#include "image_gl.h"
#include "hello_imgui/hello_imgui.h"
#include "../external/imgui/backends/imgui_impl_opengl3.h"
#include "../external/imgui/backends/imgui_impl_glfw.h"
#include "imgui_internal.h"
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "hello_imgui/internal/stb_image.h"

// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

int main(int , char *[]) {
    HelloImGui::RunnerParams params;
    params.appWindowParams.windowSize = {1280.f, 720.f};
    params.appWindowParams.windowTitle = "4K";
    params.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::NoDefaultWindow; 

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;

    params.callbacks.SetupImGuiConfig = [&]() {

    };

    params.callbacks.SetupImGuiStyle = [&]() {

        auto& io = ImGui::GetIO();
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsClassic();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows
        // can look identical to regular ones.

        ImGuiStyle& style = ImGui::GetStyle();

        style.WindowRounding = 6.0f;
        style.WindowBorderSize = 0.0f;
        style.PopupBorderSize = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        style.Colors[ImGuiCol_FrameBg] = ImVec4(0.277f, 0.160f, 0.480f, 0.540f);

        // Load a first font
        ImFont* font = io.Fonts->AddFontDefault();

        // Add character ranges and merge into the previous font
        // The ranges array is not copied by the AddFont* functions and is used lazily
        // so ensure it is available at the time of building or calling GetTexDataAsRGBA32().
        static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 }; // Will not be copied by AddFont* so keep in scope.
        ImFontConfig config;
        config.MergeMode = true;
        io.Fonts->AddFontFromFileTTF("DroidSans.ttf", 18.0f, &config, io.Fonts->GetGlyphRangesJapanese()); // Merge into first font
        io.Fonts->AddFontFromFileTTF("fontawesome-webfont.ttf", 18.0f, &config, icons_ranges);             // Merge into first font
        io.Fonts->Build();
    };

    params.callbacks.ShowGui = [&]() {

        auto& io = ImGui::GetIO();

        int logo_texture_width = 0;
        int logo_texture_height = 0;
        GLuint logo_texture = 0;
        bool LogoTex = LoadTextureFromFile("images/scenes/title_screen/logo.png", &logo_texture, &logo_texture_width, &logo_texture_height);
        IM_ASSERT(LogoTex);

        ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f,0.5f));
        ImGui::SetNextWindowSize(ImVec2(960, 640), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowFocus();
        ImGui::Begin("4K Engine", NULL);
        {
            // Using a Child allow to fill all the space of the window.
            // It also alows customization
            ImGui::BeginChild("GameRender");
            // Get the size of the child (i.e. the whole draw size of the windows).
            ImVec2 wsize = ImGui::GetWindowSize();
            ImGui::Image((void*)(intptr_t)logo_texture, ImVec2(logo_texture_width / 2, logo_texture_height / 2));
            ImGui::EndChild();
        }
        ImGui::End();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&params.imGuiWindowParams.backgroundColor); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

            #ifndef HELLOIMGUI_MOBILEDEVICE
            if (ImGui::Button("Quit"))
                params.appShallExit = true;
            #endif
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        if(ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if(ImGui::MenuItem("New"))
                {
                    //Do something
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit"))
            {
                if(ImGui::MenuItem("New"))
                {
                    //Do something
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("About"))
            {
                if(ImGui::MenuItem("About 4K Engine"))
                {
                    //Do something
                }

                if(ImGui::MenuItem("About ImGui"))
                {
                    //Do something
                }
                if(ImGui::MenuItem("About Hello, ImGui"))
                {
                    //Do something
                }

                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Help"))
            {
                if(ImGui::BeginMenu("\uF02D " "Docs"))
                {
                    if(ImGui::MenuItem(u8"Readme - Finished: \u2717"))
                    {

                    }
                    if(ImGui::MenuItem(u8"Wiki Page - Finished: \u2717"))
                    {

                    }
                    if(ImGui::MenuItem(u8"ReadTheDocs Page - Finished \u2717"))
                    {

                    }
                }
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }
            
        ImGui::Render();
    };
    HelloImGui::Run(params);
    return 0;
}
