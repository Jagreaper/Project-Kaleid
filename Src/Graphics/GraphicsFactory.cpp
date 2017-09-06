#include "stdafx.hpp"
#include "GraphicsFactory.hpp"

using namespace Kaleid::Graphics;


Window* GraphicsFactory::CreateWindow(const unsigned int width, const unsigned int height, const char* title)
{
	Window* window = new Window();
	window->SetSize(width, height);
	window->SetTitle(title);
	return window;
}

ShaderProgram* CreateShaderProgram(const char** sources, const ShaderType* types, const unsigned short count)
{
	return NULL;
}