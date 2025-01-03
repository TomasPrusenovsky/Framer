#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>


namespace fr {
    class Window
    {
    public:
        Window(uint32_t width, uint32_t height, const char* title);
        ~Window();

        void OnUpdate();
        void SetVSync(bool enabled);
        void ShowFPS();
        void SetTickDelay(double delay) { m_Tick.SetDelay(delay); }
        GLFWwindow* Ptr() const {return m_Window;}

        bool IsTick() const { return m_Tick.tick; }
        bool IsRunning() const { return m_Settings.shouldRun; }
        uint32_t Width() const { return m_Settings.width; }
        uint32_t Height() const { return m_Settings.height; }
        float AspectRatio() const { return (float)Width() / (float)Height(); }
        float DeltaTime() const { return static_cast<float>(m_Time.delta); }
        float FPS() const { return m_FPS; }
        float MouseX() const { return m_Settings.mouse.posX; }
        float MouseY() const { return m_Settings.mouse.posY; }

    private:
        struct Mouse
        {
            float posX;
            float posY;
        };

        struct Settings
        {
            uint32_t width;
            uint32_t height;
            std::string title;
            int openGL_major;
            int openGL_minor;
            bool VSync = true;
            bool shouldRun = true;
            bool isMinimized = false;
            Mouse mouse;
        };

        struct Time
        {
            double curr = 0;
            double prev = 0;
            double delta = 0;

            void Update();
        };

        struct Tick
        {
            bool tick = false;
            double prevTime = 0;
            double delay = 1.0 / 5.0;
            void SetDelay(double del) { delay = del; }
        };

        Settings m_Settings;
        Time m_Time;
        Tick m_Tick;
        double m_FPS = 0;

        void Init();
        void Update();
        void CreateWindow();
        void SetCallBacks();
        void SetTitle(const std::string& title);
        GLFWwindow* m_Window = nullptr;

    };
}
