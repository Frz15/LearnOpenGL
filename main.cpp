#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"

#include <iostream>
#include <string>
#include <math.h>

#include "Shader.h"

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

float vertices[] = {
    -0.9f, -0.9f, 0.0f, -0.3f, 0.3f, 0.0f,
     0.9f, -0.9f, 0.0f, -0.2f, 0.2f, 0.0f,
     0.9f,  0.5f, 0.0f, -0.3f, 0.4f, 0.0f,
    -0.9f,  0.9f, 0.0f, -0.2f, 0.15f, 0.0f,
    0.9f,  0.9f, 0.0f, -0.3f, 0.4f, 0.0f,
    -0.9f,  0.3f, 0.0f, -0.2f, 0.15f, 0.0f
    };

float vertices2[] = {
    -0.5f, -0.5f, 0.0f,  0.3f, 0.3f, 0.0f,
    0.5f,  -0.5f, 0.0f,  0.2f, 0.2f, 1.0f,
    0.5f,   0.1f, 0.0f,  0.3f, 0.4f, 1.0f,
    -0.5f,  0.5f, 0.0f,  0.2f, 0.15f, 0.0f,
    0.5f,   0.1f, 0.0f,  0.3f, 0.4f, 0.0f,
    -0.5f,  0.5f, 0.0f,  0.2f, 0.15f, 1.0f
    };

unsigned int indices[] = {
    0,1,3,
    1,2,3
};

GLFWwindow *window;
int vertexColotLocation;

void init();
void setVAO();

int main()
{

    init();
    setVAO();
    Shader shader = Shader();
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window))
    {
        float time = glfwGetTime();
        float greenValue = sin(time)/2.0f + 0.5f;
        float redValue = cos(time)/3 + 0.5f;
        glClearColor(redValue, 0.5f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.useShader();
        // glUniform4f(vertexColotLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

void init()
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MainWindow", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
}

void setVAO()
{
    unsigned int VBO[2], VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3*sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}