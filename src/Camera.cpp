#include "Camera.h"

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

namespace fr {
    Camera::Camera(const fr::Window &window, const float fov) :
        m_window_cr(window), m_Data({fov})
    {
    }

    glm::mat4 Camera::GetViewMatrix() const {
        auto view = glm::mat4(1.0f);
        view = glm::lookAt(m_Position, m_Position + m_Orientation, m_Up);
        return view;
    }

    glm::mat4 Camera::GetProjectionMatrix() const {
        auto projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(m_Data.fov), m_window_cr.AspectRatio(), m_Data.nearPlane, m_Data.farPlane);
        return projection;
    }

    void Camera::OnUpdate() {
        	// Handles key inputs
    	auto window = m_window_cr.Ptr();
		float width = m_window_cr.Width();
    	float height = m_window_cr.Height();

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			m_Position += m_Data.speed * m_Orientation;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			m_Position += m_Data.speed * -glm::normalize(glm::cross(m_Orientation, m_Up));
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			m_Position += m_Data.speed * -m_Orientation;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			m_Position += m_Data.speed * glm::normalize(glm::cross(m_Orientation, m_Up));
		}
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			m_Position += m_Data.speed * m_Up;
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		{
			m_Position += m_Data.speed * -m_Up;
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		{
			m_Data.speed = 0.4f;
		}
		else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
		{
			m_Data.speed = 0.1f;
		}


		// Handles mouse inputs
		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			// Hides mouse cursor
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

			// Prevents camera from jumping on the first click
			if (firstClick)
			{
				glfwSetCursorPos(window, (width / 2), (height / 2));
				firstClick = false;
			}

			// Stores the coordinates of the cursor
			double mouseX;
			double mouseY;
			// Fetches the coordinates of the cursor
			glfwGetCursorPos(window, &mouseX, &mouseY);

			// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
			// and then "transforms" them into degrees 
			float rotX = m_Data.sensitivity * (float)(mouseY - (height / 2)) / height;
			float rotY = m_Data.sensitivity * (float)(mouseX - (width / 2)) / width;

			// Calculates upcoming vertical change in the m_Orientation
			glm::vec3 newm_Orientation = glm::rotate(m_Orientation, glm::radians(-rotX), glm::normalize(glm::cross(m_Orientation, m_Up)));

			// Decides whether or not the next vertical m_Orientation is legal or not
			if (abs(glm::angle(newm_Orientation, m_Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
			{
				m_Orientation = newm_Orientation;
			}

			// Rotates the m_Orientation left and right
			m_Orientation = glm::rotate(m_Orientation, glm::radians(-rotY), m_Up);

			// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
			glfwSetCursorPos(window, (width / 2), (height / 2));
		}
		else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			// Unhides cursor since camera is not looking around anymore
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			// Makes sure the next time the camera looks around it doesn't jump
			firstClick = true;
		}
    }
}
