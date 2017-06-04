#ifndef _INPUT_INPUTMANAGER_
#define _INPUT_INPUTMANAGER_
#include <templates\Singleton.h>
#include <map>
#include <vector>
#include <core/atomic/Types.h>
#include <GLFW\glfw3.h>
#include <core\math\Math.h>

#define INPUT_MANAGER Palette3D::InputManager::getInstance()

namespace Palette3D
{
	class InputManager : public Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager() {}


		void update();

		void sendGLFWKeyEvent(I32 key, I32 scancode, I32 action, I32 mode);

		Vec2 getMousePosition();

		void createAxis(std::string axisname, I32 scancode);
		F32 getAxis();
		bool getKey(I32 key);
		bool getKeyDown(I32 key);
		bool getKeyUp(I32 key);


		bool getMouseButton(I32 button);
		bool getMouseButtonDown(I32 button);
		bool getMouseButtonUp(I32 button);

	private:
		//map of keys
		std::map<I32, bool> mKeys;
		
		//Keys that went down or up this update frame
		//make these maps too?
		std::vector<I32> mKeysDown;
		std::vector<I32> mKeysUp;

		//Idea from unity
		//Not implemented
		std::map<std::string, F32> mAxis;
		Vec2 mMousePos;

	


	};
}










#endif // !_INPUT_INPUTMANAGER_
