#pragma once

#include <GLFW/glfw3.h>
#include <functional>


namespace fr {
    class ImGuiImpl {
    private:
        ImGuiImpl() = default;
        void Init(GLFWwindow* window);
        void BeginFrame(const std::function<void()>& clearFunc);
        void EndFrame(GLFWwindow* window);

        friend class Window;

    };
}
