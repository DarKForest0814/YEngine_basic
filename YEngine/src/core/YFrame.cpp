#include "iostream"

#include "../../headers/YFrame.h"


YFrame::YFrame(int w,int h)
{
  glfwInit();

  YFrame::window = glfwCreateWindow(w,h,"YEngine 0.0.0 13.02.2021", NULL, NULL);

  if (YFrame::window == NULL)
  { 
    std::cout << "Faild to initialieze GLFW window" << std::endl;
    glfwTerminate();
    return;
  }

  glViewport(0, 0, w, h);
  glfwMakeContextCurrent(YFrame::window);
};

void YFrame::updateWindow()
{
  glfwSwapBuffers(YFrame::window);
  glfwPollEvents();
};

void YFrame::closeWindow()
{
  glfwTerminate();
};

GLFWwindow* YFrame::getWindow()
{
  return YFrame::window;
};
