#ifndef _WINDOW_WINDOW_MANAGER_
#define _WINDOW_WINDOW_MANAGER_

#include <GLFW\glfw3.h>
#include <templates\Singleton.h>
#include <core\atomic\Types.h>

#define WINDOW_MANAGER Palette3D::WindowManager::getInstance()
namespace Palette3D {
	//this is only for GLFW right now
	//In the future every function here must work the same way
	class WindowManager : public Singleton<WindowManager> {

	public:
		WindowManager(I32 width, I32 height);
		virtual ~WindowManager() {};

		void setResizeable(bool b);
		GLFWwindow * getWindowPtr() { return mpWindow; }

	private:
		GLFWwindow * mpWindow;
	
	};
	
}



#endif