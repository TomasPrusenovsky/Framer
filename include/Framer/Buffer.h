#pragma once
#include <glad/glad.h>

namespace fr
{
    class Buffer
    {
    public:
        Buffer(const GLvoid* data, GLsizeiptr size, GLenum usage);
        Buffer(const GLvoid* data, GLsizeiptr size);

        const GLuint ID() const { return m_ID; }

    private:
        GLuint m_ID = 0;
    };
}