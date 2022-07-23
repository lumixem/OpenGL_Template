#pragma once
#include "glad/glad.h"

class FileManager;

class ShaderManager
{
public:

	GLuint CreateProgram(GLuint vertexShader, GLuint fragmentShader);
	GLuint LoadAndMakeShader(FileManager* fileManager, GLenum type, const char* filePath);
	GLuint MakeShader(GLenum type, const char* shaderSrc);

	GLint shaderProgramID;

private:
	void CheckShaderForErrors(GLuint shaderID);
	void CheckProgramForErrors(GLuint programID);
};

