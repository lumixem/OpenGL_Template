#include "Renderer.h"
#include "ShaderManager.h"
#include "FileManager.h"
#include "Triangle.h"

ShaderManager* shaderManager = new ShaderManager();
FileManager* fileManager = new FileManager();
Triangle* triangle;

void Renderer::Init()
{
	triangle = new Triangle(shaderManager, fileManager);
}

void Renderer::Render()
{
	triangle->Draw();
}