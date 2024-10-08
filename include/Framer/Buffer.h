#pragma once
#include <glad/glad.h>

namespace fr
{
    class Buffer
    {
    public:
        Buffer();
        Buffer(const GLvoid* data, GLsizeiptr size, GLenum usage);
        Buffer(const GLvoid* data, GLsizeiptr size);

        [[nodiscard]] GLuint ID() const { return m_ID; }

    private:
        GLuint m_ID = 0;
    };
}