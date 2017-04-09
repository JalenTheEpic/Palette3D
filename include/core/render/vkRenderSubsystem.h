/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/


#ifndef _CORE_RENDER_VKRENDERSUBSYSTEM_
#define _CORE_RENDER_VKRENDERSUBSYSTEM_
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <core\atomic\Types.h>
#include <debugging\Exception.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <bitset>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

namespace Palette3D 
{
	class VkRenderSubSystem 
	{
	private:
		
		VkInstance mVkInstance;
		//Initializes Vulkan. May be split into more functions later.
		void initVulkan();
	public:
		VkRenderSubSystem();
		~VkRenderSubSystem();

		

	};



	
}

#endif // !_CORE_RENDER_VKRENDERSUBSYSTEM_
