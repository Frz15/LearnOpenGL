#include "external/glad/glad.h"
#include "external/GLFW/glfw3.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "demo", NULL, NULL);

    std::cout << "Window Created" << std::endl;

    glfwMakeContextCurrent(window);

    // 初始化GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Init Failed" << std::endl;
        return -1;
    }

    std::cout << "Running" << std::endl;

    //设置视口
    glViewport(0, 0, 800, 600);

    //注册窗口监听
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 渲染循环
    while ( !glfwWindowShouldClose(window))
    {
        // 交换颜色缓冲区
        glfwSwapBuffers(window);

        // 检测ESC按键是否按下
        processInput(window);

        // 渲染指令 —— 用这个颜色来清空屏幕
        // 设置清空颜色
        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

        // 清除屏幕
        glClear(GL_COLOR_BUFFER_BIT);

        // 检查是否触发相关事件
        glfwPollEvents();
    }
    
    // 删除/释放资源
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0, width, height);
}

// 输入监听
void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}