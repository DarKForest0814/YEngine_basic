#include "../../headers/YRenderer.h"

// Initializes GLEW
YRenderer::YRenderer()
{
  glewInit();
};

// prepares the buffer at every itteration for the purpose of rendering
void YRenderer::prepare()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
};

// will render a given entity (with an assigned shader)
void YRenderer::render(YMesh* mesh)
{
  glBindVertexArray(mesh->getVaoID());

  glDrawArrays(GL_TRIANGLES, 0,3);

  glBindVertexArray(0);
};
