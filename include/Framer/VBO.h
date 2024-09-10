#pragma once
#include "Buffer.h"

namespace fr
{
    class VBO : public Buffer
    {
    public:
        using Buffer::Buffer;
        void NamedBufferStorage(GLsizeiptr size, const void* data = nullptr);
        void NamedBufferSubData(GLsizeiptr offset, GLintptr size, const void* data);
    };
}