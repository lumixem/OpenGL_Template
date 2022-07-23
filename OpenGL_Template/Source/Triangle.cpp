#include "Triangle.h"
#include "ShaderManager.h"
#include "FileManager.h"

Triangle::Triangle(ShaderManager* shaderManager, FileManager* fileManager)
{
    vertexShader = shaderManager->LoadAndMakeShader(fileManager, GL_VERTEX_SHADER, "Resources/Shaders/vertShader.vert");
    fragmentShader = shaderManager->LoadAndMakeShader(fileManager, GL_FRAGMENT_SHADER, "Resources/Shaders/fragShader.frag");
    shaderProgram = shaderManager->CreateProgram(vertexShader, fragmentShader);

    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glDeleteShader(this->vertexShader);
    glDeleteShader(this->fragmentShader);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Triangle::Draw()
{
    glUseProgram(this->shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}