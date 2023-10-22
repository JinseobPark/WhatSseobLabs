#include "ShaderManager.h"
#include <fstream>

void ShaderManager::initialize()
{
	Shader defaulter; defaulter.Load("src\\Shader\\shader.vs", "src\\Shader\\shader.fs");
	_shader_map["default"] = defaulter;

	Shader heartShader; heartShader.Load("src\\Shader\\heart.vs", "src\\Shader\\heart.fs", "src\\Shader\\heart.gs");
	_shader_map["heart"] = heartShader;
}
