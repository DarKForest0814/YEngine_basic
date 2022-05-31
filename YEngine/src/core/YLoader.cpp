#include "../../headers/YLoader.h"


YMesh *YLoader::loadToVao(float *positions,int size)
{
  GLuint vaoID;
  // generates buffers 1: amount, 2: unsigned int the buffer gets assigned to(memory address)
  glGenBuffers(1,&vaoID);
  // selecting newly created buffer by binding it 1: target (how should opengl interpret the buffer) 2: id of buffer
  glBindBuffer(GL_ARRAY_BUFFER,vaoID);
  // specifying data 1: target (how should opengl interpret the buffer) 2: set fixied size of buffer in bytes 
  // 3: pointer to data (unnecessary if array) 4: specify usage
  glBufferData(GL_ARRAY_BUFFER,size*sizeof(float),positions,GL_STATIC_DRAW);
  // the vertex attribute array needs to be enabled next
  glEnableVertexAttribArray(0);
  // telling opengl how to interpret the data, for example what means what in the given data array
  // 1: Index specification
  // 2: size (for example size of eache indecie(1 point, 2 points, 3 points or 4 points))
  // 3: type, what type of data is handled, in this case GL_FLOAT
  // 4: if data should be normalized, mapped between 1 and 0(important for colour values)
  // 5: stride, the byte offset beetween the vertexes(in this case each is the size of 2 floats)
  // 6: offset of each element of the vertexes, in this case the byte size of a float
  glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2*sizeof(float),0);

  glBindBuffer(GL_ARRAY_BUFFER,0);
  
  return new YMesh(vaoID,size);
}