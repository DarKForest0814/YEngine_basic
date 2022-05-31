#pragma once

class YFrame
{
    public:
      GLFWwindow* window;


      YFrame(int w = 0,int h = 0);
      void updateWindow();
      void closeWindow();
      GLFWwindow* getWindow();
};
