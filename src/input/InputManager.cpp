#include <input\InputManager.h>
#include <templates\Singleton.h>
#include <map>
#include <core/atomic/Types.h>
#define INPUT_MANAGER Palette3D::InputManager::getInstance()

namespace Palette3D
{




	class InputManager : public Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager();

	private:
		std::map<std::string, F32> mAxisValues;
	};

	InputManager::InputManager()
	{
	}

	InputManager::~InputManager()
	{
	}


}