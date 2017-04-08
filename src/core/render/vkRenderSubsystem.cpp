/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/
#include <core\render\vkRenderSubsystem.h>

namespace Palette3D
{



	void VkRenderSubSystem::initVulkan()
	{
		//Information about the application.
		//needed to init the vkInstance
		VkApplicationInfo appInfo {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Palette 3D Application";
		appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
		appInfo.pEngineName = "Palette3d";
		appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		//Creation info. 
		//needed to init the vkInstance
		VkInstanceCreateInfo createInfo {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		//pNext is NULL or a pointer to an extension-specific structure.
		createInfo.pNext = NULL;
		//flags is reserved for future use.
		createInfo.flags = 0; //MUST BE 0 ACCORDING TO VULKAN SPEC
		createInfo.pApplicationInfo = &appInfo;


		VkInstance * vkInstance;

		//Will create the vk instance and store it in the vk instance pointer provided as the 3rd arg
		//2nd arg is null because we are currently not doing our own memory allocation
		switch (vkCreateInstance(&createInfo,NULL,vkInstance))
		{
		case VK_ERROR_OUT_OF_HOST_MEMORY:
			break;

		case VK_ERROR_OUT_OF_DEVICE_MEMORY:
			break;

		case VK_ERROR_INITIALIZATION_FAILED:
			break;

		case VK_ERROR_LAYER_NOT_PRESENT:
			break;

		case VK_ERROR_EXTENSION_NOT_PRESENT:
			break;

		case VK_ERROR_INCOMPATIBLE_DRIVER:
			break;

		case VK_SUCCESS:
			break;
		}
	
	}

}