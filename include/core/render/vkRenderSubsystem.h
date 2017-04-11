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
		VkPhysicalDevice mPhysicalDevice;
		VkDevice mLogicalDevice;
		VkQueue graphicsQueue;

		// !----------INIT FUNCTIONS----------!
		//Initializes Vulkan. Calls other functions in this section
		void initWindow();
		void initVulkan();
		void initVkInstance();
		void checkValidationLayers();
		void choosePhysicalDevice();
		void initLogicalDevice();
		

		// !----------UTILITY FUNCTIONS----------!
		//checks if the device has the functionality we want
		//TODO:: FINISH THIS
		bool checkPhysicalDevice(VkPhysicalDevice &device);

	public:
		GLFWwindow* mWindow;


	public:
		// !----------CONSTRUCTORS/DESTRUCTORS----------!
		VkRenderSubSystem();
		~VkRenderSubSystem();

		

	};



	
}

#endif // !_CORE_RENDER_VKRENDERSUBSYSTEM_
