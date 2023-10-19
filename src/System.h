#pragma once
#include <iostream>
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"

#include "Util/Timer.h"
#include "Shader/Buffer.h"
#include "Shader/ShaderManager.h"

class System
{
public:
	System();
	~System();

	bool initialize();

	bool update();
	bool draw();
	void exit();

	bool isExit() { return glfwWindowShouldClose(_window); }

	bool glfwInitialize();

	void processInput();

	void mouse_callback(double xpos, double ypos);
	void scroll_callback(double xoffset, double yoffset);
private:
	const unsigned int SCREEN_WIDTH = 512;
	const unsigned int SCREEN_HEIGHT = 512;

	const unsigned short OPENGL_MAJOR_VERSION = 4;
	const unsigned short OPENGL_MINOR_VERSION = 6;
	bool vSync = false;

	GLFWwindow* _window = nullptr;

	Timer* _timer = nullptr;
	ShaderManager* _shader_manager = nullptr;
	Buffer* _buffer = nullptr;
};