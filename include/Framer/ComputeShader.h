#pragma once
#include "ShaderParser.h"
#include "glad/glad.h"

namespace fr {
    class ComputeShader {
    public:
        explicit ComputeShader(const std::string& file);
        [[nodiscard]] GLuint ID() const { return m_ProgramID;}

    private:
        void CreateProgram(const char* source);
        static GLuint CompileShader(const char* source);

        GLuint m_ProgramID;
    };
}