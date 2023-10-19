#include "System.h"

System::System()
{
}

System::~System()
{
	if (_timer)						delete _timer;
	if (_shader_manager)	delete _shader_manager;
}

bool System::initialize()
{
	bool result = true;
	result = glfwInitialize();
	
	if (result)
	{
		_timer = new Timer();
		_shader_manager = new ShaderManager();
		_shader_manager->initialize();
		_buffer = new Buffer();
		_buffer->initialize();
	}

	return result;
}

bool System::update()
{
	processInput();
	_timer->update();

	return true;
}

bool System::draw()
{
	float red = glm::abs(glm::cos(_timer->getTotalTime()));
	float green = glm::abs(glm::sin(_timer->getTotalTime()));
	float blue = glm::abs(glm::sin(glm::cos(_timer->getTotalTime())));
	glClearColor(red, green, 0.3f, 1.0f);
	//glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0f);
	_shader_manager->getShader("default").use();
	glBindVertexArray(_buffer->getVAO());
	glDrawArrays(GL_POINTS, 0, _buffer->getVertexSize());


	glfwSwapBuffers(_window);
	glfwPollEvents();
	return true;
}

void System::exit()
{
	glfwDestroyWindow(_window);
	glfwTerminate();
}

bool System::glfwInitialize()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


	_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HeartBeat", NULL, NULL);
	if (!_window)
	{
		std::cout << "Failed to create the GLFW window\n";
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(_window);

	auto framebuffer_size_callback = [](GLFWwindow* window, int width, int height)	{ glViewport(0, 0, width, height); };
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
	//glfwSetCursorPosCallback(_window, mouse_callback);
	//glfwSetScrollCallback(_window, scroll_callback);

	glfwSwapInterval(vSync);
	glfwSetWindowUserPointer(_window, reinterpret_cast<void*>(this));

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL context" << std::endl;
	}
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	return true;
}

void System::processInput()
{
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_window, true);
}

void System::mouse_callback(double xpos, double ypos)
{

}

void System::scroll_callback(double xoffset, double yoffset)
{

}
