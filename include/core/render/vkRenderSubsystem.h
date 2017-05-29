/*
Palette3D
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
		VkQueue mGraphicsQueue;
		VkSurfaceKHR mSurface;

		// !----------INIT FUNCTIONS----------!
		//Initializes Vulkan. Calls other functions in this section
		void initWindow();
		void initVulkan();
		void initVkInstance();
		void initDebugCallback();
		void checkValidationLayers();
		void choosePhysicalDevice();
		void initLogicalDevice();
		
		void initCommandBuffer();
		void initVkSurface();
		void bindWindow();
		// !----------UTILITY FUNCTIONS----------!
		//checks if the device has the functionality we want
		//TODO:: FINISH THIS
		bool checkPhysicalDevice(VkPhysicalDevice &device);


		

	public:
		GLFWwindow* mpWindow;


	public:
		// !----------CONSTRUCTORS/DESTRUCTORS----------!
		VkRenderSubSystem();
		~VkRenderSubSystem();



		//!---------- TEMP FUNCTIONS -------------!
		void debugRun()
		{
			while (!glfwWindowShouldClose(mpWindow)) {
				glfwPollEvents();
			}

		};
		

	};



	
}

#endif // !_CORE_RENDER_VKRENDERSUBSYSTEM_
