#include "../../headers/YMesh.h"

YMesh::YMesh(GLuint vaoID, int vertexCount)
{
  YMesh::vaoID =  vaoID;
  YMesh::vertexCount = vertexCount;
};

GLuint YMesh::getVaoID()
{
    return YMesh::vaoID;
};

int YMesh::getVertexCount()
{
    return YMesh::vertexCount;
};