#include <input\InputManager.h>
#include <window\WindowManager.h>


void  keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{

	INPUT_MANAGER->sendGLFWEvent(key,scancode,action,mode);
	


}



void mouse_callback(GLFWwindow* window, double xpos, double ypos) {};
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {};
void processInput(GLFWwindow *window) {};

namespace Palette3D
{
	InputManager * InputManager::mspInstance = nullptr;

	
	

	InputManager::InputManager()
	{
		//Set the callback functions up
		glfwSetKeyCallback(WINDOW_MANAGER->getWindowPtr(), keyCallback);
		glfwSetCursorPosCallback(WINDOW_MANAGER->getWindowPtr(), mouse_callback);
		glfwSetScrollCallback(WINDOW_MANAGER->getWindowPtr(), scroll_callback);
	}

	void InputManager::update()
	{
		glfwPollEvents();
	}

	void  InputManager::sendGLFWEvent(int key, int scancode, int action, int mode)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(WINDOW_MANAGER->getWindowPtr(), GL_TRUE);

	}

	

}