#include "ShaderManager.h"
#include "FileManager.h"
#include "stdio.h"
#include <string>

GLuint ShaderManager::LoadAndMakeShader(FileManager* fileManager, GLenum type, const char* filePath)
{
	std::string shaderSource = fileManager->LoadText(filePath);
	GLuint shader = MakeShader(type, shaderSource.c_str());
	return shader;
}

GLuint ShaderManager::MakeShader(GLenum type, const char* shaderSrc)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &shaderSrc, nullptr);
	glCompileShader(shader);
	CheckShaderForErrors(shader);
	return shader;
}

GLuint ShaderManager::CreateProgram(GLuint vertexShader, GLuint fragmentShader)
{
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	CheckProgramForErrors(shaderProgram);
	return shaderProgram;
}

void ShaderManager::CheckShaderForErrors(GLuint shaderID)
{
	GLint success;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint info = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &info);
		if (info > 1)
		{
			char* infoLog = (char*)malloc(sizeof(char) * info);
			glGetShaderInfoLog(shaderID, info, NULL, infoLog);
			printf("Error compiling shader:\n%s\n", infoLog);
			free(infoLog);
		}
		glDeleteShader(shaderID);
	}
}

void ShaderManager::CheckProgramForErrors(GLuint programID)
{
	GLint success;
	glGetProgramiv(programID, GL_LINK_STATUS, &success);

	if (!success)
	{
		GLint info = 0;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &info);
		if (info > 1)
		{
			char* infoLog = (char*)malloc(sizeof(char) * info);
			glGetProgramInfoLog(programID, info, NULL, infoLog);
			printf("Error linking program:\n%s\n", infoLog);
			free(infoLog);
		}
		glDeleteProgram(programID);
	}
}