#include "ComputeShader.h"
namespace fr {
    ComputeShader::ComputeShader(const std::string &file) {
        ShaderParser parser;
        ShaderSource computeSource = parser.GetSource(file, ShaderType::COMPUTE);
        CreateProgram(computeSource.contents.c_str());
    }

    void ComputeShader::CreateProgram(const char *source) {
        m_ProgramID = glCreateProgram();
        GLuint computeShader = CompileShader(source);
        glAttachShader(m_ProgramID, computeShader);
        glLinkProgram(m_ProgramID);

        // Check for linking errors
        GLint success;
        glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(m_ProgramID, 512, nullptr, infoLog);
            std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        glDeleteShader(computeShader);  // Shader is linked, so we can delete it
    }

    GLuint ComputeShader::CompileShader(const char *source) {
        GLuint shader = glCreateShader(GL_COMPUTE_SHADER);
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);

        // Check for compilation errors
        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "ERROR::SHADER::COMPUTE::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        return shader;
    }
}
