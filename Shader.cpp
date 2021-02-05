#include "include\glad\glad.h"

#include "Shader.h"

#include <iostream>

Shader::Shader(){
    const char* vertexShaderSource = "#version 330 core\n"
                                     "layout(location=0) in vec3 aPos;\n"
                                     "layout(location=2) in vec3 aColor;\n"
                                     "out vec3 ourColor;\n"
                                     "void main()\n"
                                     "{\n"
                                     "ourColor = vec3(aColor);\n"
                                     "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
                                     "}\n\0";

    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "in vec3 ourColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "    FragColor=vec4(ourColor, 1.0f);\n"
                                       "}\n\0";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    this->shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    this->vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
}

void Shader::useShader(){
    glUseProgram(shaderProgram);
}