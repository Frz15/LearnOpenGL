#include "include\glad\glad.h"

#include "Shader.h"

#include <iostream>

Shader::Shader(){
    const char* vertexShaderSource = "#version 330 core\n"
                                     "layout(location=0) in vec3 aPos;\n"
                                     "layout(location=1) in vec2 aTexCoord;\n"
                                     "out vec2 TexCoord;\n"
                                     "uniform mat4 transform;\n"
                                     "void main()\n"
                                     "{\n"
                                     "TexCoord = vec2(aTexCoord);\n"
                                     "gl_Position = transform*vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
                                     "}\n\0";

    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "in vec2 TexCoord;\n"
                                       "uniform sampler2D ourTexture1;\n"
                                       "uniform sampler2D ourTexture2;\n"
                                       "void main()\n"
                                       "{\n"
                                       "    FragColor=mix(texture(ourTexture1,TexCoord),texture(ourTexture2,TexCoord),0.2);\n"
                                       "}\n\0";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    this->ID = glCreateProgram();

    glAttachShader(this->ID, vertexShader);
    glAttachShader(this->ID, fragmentShader);
    glLinkProgram(this->ID);

    this->vertexColorLocation = glGetUniformLocation(this->ID, "ourColor");
}

void Shader::useShader(){
    glUseProgram(this->ID);
}