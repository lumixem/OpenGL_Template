#pragma once
#include "glad/glad.h"

class ShaderManager;
class FileManager;

class Triangle
{
public:
	Triangle(ShaderManager* shaderManager, FileManager* fileManager);

	void Draw();

private:
	GLuint VBO, VAO;
	GLuint vertexShader, fragmentShader, shaderProgram;
};