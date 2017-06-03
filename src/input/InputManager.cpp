#include <input\InputManager.h>


namespace Palette3D
{
	InputManager * InputManager::mspInstance = nullptr;









	InputManager::InputManager()
	{
		//glfwSetKeyCallback(window, InputManager::keyCallback);
	}

	void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		

		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		
	}

}