#pragma once

class YMesh
{
    GLuint vaoID;
    int vertexCount;

    public:
       YMesh(GLuint vaoID, int vertexCount);
       GLuint getVaoID();
       int getVertexCount();
};