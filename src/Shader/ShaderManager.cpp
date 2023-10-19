#include "ShaderManager.h"
#include <fstream>

void ShaderManager::initialize()
{
	Shader defaulter; defaulter.Load("src\\Shader\\shader.vs", "src\\Shader\\shader.fs");
	_shader_map["default"] = defaulter;
}
