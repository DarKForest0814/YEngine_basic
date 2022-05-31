#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include <chrono>
#include "iostream"

#include "../../headers/YFrame.h"
#include "YFrame.cpp"

#include "../../headers/YMesh.h"
#include "../models/YMesh.cpp"

#include "../../headers/YLoader.h"
#include "YLoader.cpp"

#include "../../headers/YRenderer.h"
#include "YRenderer.cpp"

#include "../shaders/YStaticShader.cpp"
#include "../../headers/YStaticShader.h"

#include "../../headers/YEngineManager.h"

using namespace std;

YEngineManager::YEngineManager()
{
  std::cout << "Initializing core YEngine. " << std::endl;

  YEngineManager::window = new YFrame(YEngineManager::width,YEngineManager::height);
  YEngineManager::renderer = new YRenderer();
  YEngineManager::staticShader = new YStaticShader((char*)"/home/toor/Desktop/Programm/code/C++/YEngine/src/shaders/shader_files/VertexShader.txt",(char*)"/home/toor/Desktop/Programm/code/C++/YEngine/src/shaders/shader_files/FragmentShader.txt");
  YEngineManager::loader = new YLoader();

  std::cout << "YEngine has succsesfully initialiezed!" << std::endl;

  float positions[6] = {
    -0.5f, -0.5f,
     0.0f,  0.5f,
     0.5f, -0.5f,
     };

  YEngineManager::mesh = YEngineManager::loader->loadToVao(positions,6);


  run();
};

void YEngineManager::processInput(GLFWwindow* window)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE)==GLFW_PRESS)
  {
    YEngineManager::running = false;
  };
};

void YEngineManager::run()
{
  YEngineManager::running = true;
  YEngineManager::render = true;
  
  GLuint firstTime = 0;
  GLuint lastTime = glutGet(GLUT_ELAPSED_TIME)/1000.0;
  GLuint passedTime = 0, unprocessedTime = 0;

  // Game loop
  while(YEngineManager::running&&!glfwWindowShouldClose(YEngineManager::window->getWindow()))
  {

    firstTime = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    passedTime = firstTime - lastTime;
    lastTime = firstTime;

    unprocessedTime += passedTime;
    YEngineManager::frameTime += passedTime;

    YEngineManager::processInput(YEngineManager::window->getWindow());

    //std::cout << "UnprocessedTime : " << unprocessedTime << std::endl;
    
    // updating
    while(unprocessedTime >= YEngineManager::UPDATE_CAP)
    {
      unprocessedTime -= YEngineManager::UPDATE_CAP;
      render = true;

      if(YEngineManager::frameTime >= 1.0)
      {
        YEngineManager::frameTime = 0;
        YEngineManager::fps = YEngineManager::frames;
        std::cout << "Frames : " << YEngineManager::fps << std::endl;
        YEngineManager::frames = 0;
      }
    }


    // rendering
    if(YEngineManager::render)
    {
      YEngineManager::renderer->prepare();

      YEngineManager::staticShader->start();
      
      YEngineManager::renderer->render(YEngineManager::mesh);

      YEngineManager::staticShader->stop();

      YEngineManager::window->updateWindow();

      YEngineManager::frames += 1;
    }

  };

  YEngineManager::window->closeWindow();
  YEngineManager::staticShader->cleanUp();
  std::cout << "YEngine has succsesfully stoped!" << std::endl;
};
