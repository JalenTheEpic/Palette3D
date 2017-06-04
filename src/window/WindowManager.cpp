#include <window\WindowManager.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
	glViewport(0, 0, width, height);
};

namespace Palette3D
{
	WindowManager * WindowManager::mspInstance = nullptr;

	WindowManager::WindowManager(I32 width, I32 height)
	{
		
		if (!glfwInit())
		{
			//error
		}

		//GL setup
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, 1);



		//Making the window
		mpWindow = glfwCreateWindow(width, height, "Palette3D", nullptr, nullptr);
		if (mpWindow == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		//Makes the context of the specified window current for the calling thread.
		glfwMakeContextCurrent(mpWindow);

		glfwSetFramebufferSizeCallback(WINDOW_MANAGER->getWindowPtr(), framebuffer_size_callback);



		//Sets our viewport to that framebuffer size.
		glViewport(0, 0, width, height);
	}


	

	void WindowManager::setResizeable(bool b)
	{
		glfwWindowHint(GLFW_RESIZABLE, b);
	}

}