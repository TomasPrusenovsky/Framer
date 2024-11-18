#pragma once
#include "VBO.h"
#include "EBO.h"

namespace fr
{
    class VAO
    {
    public:
        VAO();
        ~VAO();

        void Bind();
        void Unbind();

        void BindVertexBuffer(const VBO& vbo, GLuint bindindex, GLintptr offset, GLsizei stride);
        void BindElementBuffer(const EBO& ebo);
        void SpecifyData(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
        void SpecifyData(GLuint attribindex, GLint size, GLuint relativeoffset);


    private:
        GLuint m_ID;
    };
}