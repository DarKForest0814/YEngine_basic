#pragma once

class YShaderProgramm
{
    GLuint programID;

    public:
      explicit YShaderProgramm(char* vertexFile, char* fragmentFile);

      void start();
      void stop();
      void cleanUp();
      void bindAttributes(int attribute, char* varName);
      GLuint loadShader(const char* vertexFile, const char* fragmentFile);
};

std::string readFile(const char *filePath);