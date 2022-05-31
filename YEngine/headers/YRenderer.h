#pragma once

class YRenderer
{
    public:
      YRenderer();
      void prepare();
      void render(YMesh* mesh);
      void createProjectionMatrix();
};