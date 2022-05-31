#pragma once

class YStaticShader: public YShaderProgramm
{
    static char* VERTEX_FILE;
    static char* FRAGMENT_FILE;
    
    public:
    
      explicit YStaticShader(char* vertexFile, char* fragmentFile) : YShaderProgramm(vertexFile,fragmentFile){};
};