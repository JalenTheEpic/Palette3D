#ifndef _INPUT_INPUTMANAGER_
#define _INPUT_INPUTMANAGER_
#include <templates\Singleton.h>
#include <map>
#include <core/atomic/Types.h>
#include <GLFW\glfw3.h>

#define INPUT_MANAGER Palette3D::InputManager::getInstance()

namespace Palette3D
{
	class InputManager : public Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager() {}


		void update();

		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);


		F32 getAxis();
		bool getKey();
		bool getKeyDown();
		bool getKeyUp();


		bool getMouseButton();
		bool getMouseButtonDown();
		bool getMouseButtonUp();

	private:
		//map<KeyCode, State>  Key -> 0000 0000 
		//Currently down bit: 0x01 
		//Pressed this update frame: 0x02
		//Released this update frame: 0x04
		std::map<I16, I8> mKeys;

	


	};
}






#endif // !_INPUT_INPUTMANAGER_
