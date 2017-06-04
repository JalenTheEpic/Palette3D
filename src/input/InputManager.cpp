#include <input\InputManager.h>
#include <window\WindowManager.h>


void  keyCallback(GLFWwindow* window, I32 key, I32 scancode, I32 action, I32 mode)
{

	INPUT_MANAGER->sendGLFWKeyEvent(key,scancode,action,mode);
	


}



void mouse_callback(GLFWwindow* window, double xpos, double ypos) 
{

	

};
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {};


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
		mKeysDown.clear();
		mKeysUp.clear();
		glfwPollEvents();
	}

	void  InputManager::sendGLFWKeyEvent(I32 key, I32 scancode, I32 action, I32 mode)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(WINDOW_MANAGER->getWindowPtr(), GL_TRUE);
		else
		{
			if (action == GLFW_PRESS)
			{
				mKeysDown.push_back(key);
				if (mKeys.count(key))
				{
					mKeys[key] = true;
				}
				else
				{
					mKeys.insert(std::pair<I32,bool>(key,true));
				}
			}
			else if(action == GLFW_RELEASE)
			{
				mKeysUp.push_back(key);
				if (mKeys.count(key))
				{
					mKeys[key] = false;
				}
				else
				{
					mKeys.insert(std::pair<I32, bool>(key, false));
				}
			}
		
		}

	}

	

	bool InputManager::getKey(I32 key)
	{
		if (mKeys.count(key))
			return mKeys[key];

		return false;
	}

	bool InputManager::getKeyDown(I32 key)
	{
		auto it = std::find(mKeysDown.begin(), mKeysDown.end(), key);
		return (it != mKeysDown.end());
		
	}

	bool InputManager::getKeyUp(I32 key)
	{
		auto it = std::find(mKeysUp.begin(), mKeysUp.end(), key);
		return (it != mKeysUp.end());
	}

}