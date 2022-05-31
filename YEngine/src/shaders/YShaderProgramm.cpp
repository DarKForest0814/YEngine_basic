#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "../../headers/YShaderProgramm.h"

YShaderProgramm::YShaderProgramm(char* vertexFile, char* fragmentFile)
{
    YShaderProgramm::programID = YShaderProgramm::loadShader(vertexFile,fragmentFile);
};

std::string readFile(const char *filePath) 
{
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) 
    {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";

    while(!fileStream.eof()) 
    {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
};

GLuint YShaderProgramm::loadShader(const char* vertexFile, const char* fragmentFile)
{
    GLuint program = glCreateProgram();
    
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    int result;

    // Read shaders

    std::string vertShaderStr = readFile(vertexFile);
    std::string fragShaderStr = readFile(fragmentFile); 

    const char *vertShaderSrc = vertShaderStr.c_str();
    const char *fragShaderSrc = fragShaderStr.c_str();

    // Compile vertex shader

    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(vertexShaderID, 1, &vertShaderSrc, nullptr);
    glCompileShader(vertexShaderID);

    // error handeling
    glGetShaderiv(vertexShaderID,GL_COMPILE_STATUS,&result);

    if(result == GL_FALSE)
    {
        int length;
        glGetShaderiv(vertexShaderID,GL_INFO_LOG_LENGTH,&length);
        char* message = (char*) alloca(length*sizeof(char));
        glGetShaderInfoLog(vertexShaderID,length, &length, message);
        std::cout << "Failed to compile vertex shader : " << std::endl;
        std::cout << message << std::endl;
        return 0;
    }

    

    // Compile fragment shader

    std::cout << "Compiling fragment shader." << std::endl;
    glShaderSource(fragmentShaderID, 1, &fragShaderSrc, nullptr);
    glCompileShader(fragmentShaderID);

    // error handeling
    glGetShaderiv(fragmentShaderID,GL_COMPILE_STATUS,&result);

    if(result == GL_FALSE)
    {
        int length;
        glGetShaderiv(fragmentShaderID,GL_INFO_LOG_LENGTH,&length);
        char* message = (char*) alloca(length*sizeof(char));
        glGetShaderInfoLog(fragmentShaderID,length, &length, message);
        std::cout << "Failed to compile fragment shader : " << std::endl;
        std::cout << message << std::endl;
        return 0;
    }

    std::cout << "Linking program: " << program << std::endl;

    glAttachShader(program, vertexShaderID);
    glAttachShader(program, fragmentShaderID);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(fragmentShaderID);
    glDeleteShader(vertexShaderID);    

    return program;

};

void YShaderProgramm::start()
{
  glUseProgram(YShaderProgramm::programID);
};

void YShaderProgramm::stop()
{
  glUseProgram(0);
};

void YShaderProgramm::cleanUp()
{
    YShaderProgramm::stop();
    glDeleteProgram(YShaderProgramm::programID);
};
