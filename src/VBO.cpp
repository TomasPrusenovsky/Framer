#include "VBO.h"
void fr::VBO::NamedBufferStorage(GLsizeiptr size, const void *data) {
    glNamedBufferStorage(ID(), size, data, GL_DYNAMIC_STORAGE_BIT);
}
void fr::VBO::NamedBufferSubData(GLsizeiptr offset, GLintptr size, const void *data) {
    glNamedBufferSubData(ID(), offset, size, data);
}
