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


#pragma region vkInstanceInit
		//Information about the application.
		//needed to init the vkInstance
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Application";
		appInfo.pNext = NULL;
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "Palette3d";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;


	/////////////////////FINISH ME/////////////////////////////////////////////////////
		////getting layer info

		//U32 instanceLayerCount = 0;
		////Gets the layer count and store it in arg 1
		//vkEnumerateInstanceLayerProperties(&instanceLayerCount, nullptr);
		//VkLayerProperties layerProperty;
		//vkEnumerateInstanceLayerProperties(&instanceLayerCount, &layerProperty);
	//////////////////////////////////////////////////////////////////////////////////


		//Creation info. 
		//needed to init the vkInstance
		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		//pNext is NULL or a pointer to an extension-specific structure.
		createInfo.pNext = nullptr;
		//flags is reserved for future use.
		createInfo.flags = 0; //MUST BE 0 ACCORDING TO VULKAN SPEC
		createInfo.pApplicationInfo = &appInfo;

		//Glfw handles getting the extensions for us
		U32 glfwExtensionCount = 0;
		const char** glfwExtensions;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;

		//end getting extensions

		createInfo.enabledLayerCount = 0;
		createInfo.ppEnabledLayerNames = {};
		
	
		

		//Will create the vk instance and store it in the vk instance pointer provided as the 3rd arg
		//2nd arg is null because we are currently not doing our own memory allocation
		switch (vkCreateInstance(&createInfo,nullptr,&mVkInstance)) //change this to use assertions?
		{
		case VK_ERROR_OUT_OF_HOST_MEMORY:
			THROW_EXCEPTION("Error: Out of host memory",ExceptionType::OutOfMemory);
			break;

		case VK_ERROR_OUT_OF_DEVICE_MEMORY:
			THROW_EXCEPTION("Error: Out of device memory", ExceptionType::OutOfMemory);
			break;

		case VK_ERROR_INITIALIZATION_FAILED:
			THROW_EXCEPTION("Error: Initialization failed", ExceptionType::Failure);
			break;

		case VK_ERROR_LAYER_NOT_PRESENT:
			THROW_EXCEPTION("Error: Layer not present", ExceptionType::Failure);
			break;

		case VK_ERROR_EXTENSION_NOT_PRESENT:
			THROW_EXCEPTION("Error: Extension not present", ExceptionType::Failure);
			break;

		case VK_ERROR_INCOMPATIBLE_DRIVER:
			THROW_EXCEPTION("Error: Incompatible Driver", ExceptionType::Failure);
			break;

		case VK_SUCCESS:
			break;
		}
#pragma endregion vkInstanceInit
	

#pragma region vkDeviceEnumerate
		U32 deviceCount = 0;
		VkResult result = vkEnumeratePhysicalDevices(mVkInstance,&deviceCount,nullptr);
		assert(result == VK_SUCCESS);
		assert(deviceCount >= 1);


		std::vector<VkPhysicalDevice> physicalDevices(deviceCount);
		result = vkEnumeratePhysicalDevices(mVkInstance, &deviceCount, physicalDevices.data());
		assert(result == VK_SUCCESS);
		

		VkPhysicalDeviceProperties physicalProperties = {};

		for (U32 i = 0; i < deviceCount; i++)
		{


			vkGetPhysicalDeviceProperties(physicalDevices[i], &physicalProperties);
#if _DEBUG
			fprintf(stdout, "%d Device(s)\n", deviceCount);
			fprintf(stdout, "Device Name:    %s\n", physicalProperties.deviceName);
			fprintf(stdout, "Device Type:    %d\n", physicalProperties.deviceType);
			fprintf(stdout, "Driver Version: %d\n", physicalProperties.driverVersion);

			fprintf(stdout, "API Version:    %d.%d.%d\n",
				VK_VERSION_MAJOR(physicalProperties.apiVersion),
				VK_VERSION_MINOR(physicalProperties.apiVersion),
				VK_VERSION_PATCH(physicalProperties.apiVersion));

#endif
		}
#pragma endregion vkDeviceEnumerate

		
#pragma region Get_QueueFamilies_Support
		//Not sure if this is needed right now. Will revisit
#if _DEBUG
		U32 queueFamilyPropertyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(physicalDevices[0],&queueFamilyPropertyCount, nullptr);
		fprintf(stdout, "%d QueueFamilyPropertyCount(s)\n", queueFamilyPropertyCount);


		std::vector<VkQueueFamilyProperties> queueFamilyProps(queueFamilyPropertyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(physicalDevices[0], &queueFamilyPropertyCount, queueFamilyProps.data());

		/* at least one queue family of at least one physical device exposed by the implementation MUST support both graphics and compute operations.*/
		for (VkQueueFamilyProperties q:queueFamilyProps)
		{
			std::bitset<4> y(q.queueFlags);
			
			std::cout <<"Queue Flag: " << y <<std::endl;

			std::cout << "MinImageGran(" << q.minImageTransferGranularity.width << ",";
			std::cout<< q.minImageTransferGranularity.height << "," <<q.minImageTransferGranularity.depth << ")" <<std::endl;
			
		}

#endif
		//minImageTransferGranularity 


#pragma endregion Get_QueueFamilies_Support


#pragma region create_logical_device


#pragma endregion
	}

	VkRenderSubSystem::VkRenderSubSystem()
	{
		initVulkan();
	}

	VkRenderSubSystem::~VkRenderSubSystem()
	{
		//vkDestroyInstance(mVkInstance, nullptr);
	}

}