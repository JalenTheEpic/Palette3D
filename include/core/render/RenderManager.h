/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/


#ifndef _CORE_RENDER_RENDERMANAGER_
#define _CORE_RENDER_RENDERMANAGER_


#define P3DVULKAN
//#define P3DOPENGL

#include <core\atomic\Types.h>
#include <templates\Singleton.h>
namespace Palette3D
{

	class RenderManager : public Singleton<RenderManager>
	{
	private:
		void initWindow();
		void initRenderingSubsystem();

	public:
		RenderManager()
		{
			initWindow();
			initRenderingSubsystem();
			

		
		
		}
		~RenderManager();
		


	};




}
#endif // !_CORE_RENDER_RENDERMANAGER_
