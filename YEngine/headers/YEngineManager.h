#pragma once

class YEngineManager
{
   public:
      YFrame* window;
      YRenderer* renderer;
      YStaticShader* staticShader;
      YLoader* loader;
      YMesh* mesh;
      
      int width = 800;
      int height = 800;
      GLuint frameTime = 0;
      int frames = 0;
      int fps = 0;
      double UPDATE_CAP = 1.0/60.0;
      bool running;
      bool render;

      YEngineManager();
      void processInput(GLFWwindow* window);
      static void stop();
      void run();
};