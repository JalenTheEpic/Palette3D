/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/
#include <core\render\RenderManager.h>

namespace Palette3D
{
	template<> RenderManager * Singleton<RenderManager>::mspInstance = nullptr;


	void RenderManager::initWindow()
	{
#ifdef P3DVULKAN

#endif // P3DVULKAN

#ifdef P3DOPENGL

#endif // P3DOPENGL
	}

	void RenderManager::initRenderingSubsystem()
	{
#ifdef P3DVULKAN

#endif // P3DVULKAN

#ifdef P3DOPENGL

#endif // P3DOPENGL
	}

}