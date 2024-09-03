#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include "Window.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

namespace fr {
    class Camera {
    public:
        Camera(const Window& window, float fov);
        [[nodiscard]] glm::mat4 GetViewMatrix() const; // TODO: might be memory leak
        [[nodiscard]] glm::mat4 GetProjectionMatrix() const; // TODO: might be memory leak]
        void OnUpdate();
    private:
        const Window& m_window_cr;
        struct Data {
            float fov;
            float nearPlane = 0.01f;
            float farPlane = 1000.0f;
            float speed = 0.1f;
            float sensitivity = 100.0f;
        };

        Data m_Data;
        bool firstClick = true;

        // Stores the main vectors of the camera
        glm::vec3 m_Position = glm::vec3(0.0f);
        glm::vec3 m_Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
    };
}


