/*
Palette3D
Copyright (c) 2017 Jalen Cureton, William Buell
Licensed under the terms of the MIT License (see LICENSE.txt)
*/
#include <core\render\vkRenderSubsystem.h>

namespace Palette3D
{


	// !----------INIT FUNCTIONS----------!

	void VkRenderSubSystem::initWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		mWindow = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
	}

	void VkRenderSubSystem::initVulkan()
	{

		initWindow();
		initVkInstance();
	
		choosePhysicalDevice();
		initLogicalDevice();



	}

	void VkRenderSubSystem::initVkInstance()
	{

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
		switch (vkCreateInstance(&createInfo, nullptr, &mVkInstance)) //change this to use assertions?
		{
		case VK_ERROR_OUT_OF_HOST_MEMORY:
			THROW_EXCEPTION("Error: Out of host memory", ExceptionType::OutOfMemory);
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

	}

	void VkRenderSubSystem::choosePhysicalDevice()
	{
		//see how many vulkan supported devices we have
		U32 deviceCount = 0;
		VkResult result = vkEnumeratePhysicalDevices(mVkInstance, &deviceCount, nullptr);
		assert(result == VK_SUCCESS);
		assert(deviceCount >= 1);

		//gets handles to the physical devices supported by vulkan
		std::vector<VkPhysicalDevice> physicalDevices(deviceCount);
		result = vkEnumeratePhysicalDevices(mVkInstance, &deviceCount, physicalDevices.data());
		assert(result == VK_SUCCESS);

		

		//for now since my computer only has 1 gpu we'll just hard code this in
		mPhysicalDevice = physicalDevices[0];


	
	}

	void VkRenderSubSystem::initLogicalDevice()
	{
#pragma region Queue_Create
		
		//Split into a function when more queues will be used
		//currently only enables the grapics queue
		U32 queueFamilyPropertyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyPropertyCount, nullptr);
		fprintf(stdout, "%d QueueFamilyPropertyCount(s)\n", queueFamilyPropertyCount);


		std::vector<VkQueueFamilyProperties> queueFamilyProps(queueFamilyPropertyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyPropertyCount, queueFamilyProps.data());
		
		U16 graphicsQueueIndex = 0;
		for (auto queue: queueFamilyProps)
		{	
			if (queue.queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				break;
			}
			graphicsQueueIndex++;
			if (graphicsQueueIndex > queueFamilyPropertyCount)
				THROW_EXCEPTION("NO GRAPHICS QUEUE FOUND",ExceptionType::IndexOutOfRange);
		}

		//Creating a single graphics queue family
		VkDeviceQueueCreateInfo queueCreateInfo = {};
		queueCreateInfo.flags = 0;
		queueCreateInfo.pNext = nullptr;
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.queueFamilyIndex = graphicsQueueIndex;
		queueCreateInfo.queueCount = 1;
		F32 priority = 1.f;
		queueCreateInfo.pQueuePriorities = &priority;
#pragma endregion

#pragma region REVISIT

		//COME BACK TO ME WHEN WE DO CRAZY STUFF
		VkPhysicalDeviceFeatures deviceFeatures = {};

#pragma endregion

		VkDeviceCreateInfo deviceCreateInfo = {};
		deviceCreateInfo.enabledExtensionCount = 0;
		//deviceCreateInfo.enabledLayerCount = 0;
		deviceCreateInfo.flags = 0;
		deviceCreateInfo.pEnabledFeatures = &deviceFeatures; //ptr to a VkPhysicalDeviceFeatures struct
		deviceCreateInfo.pNext = nullptr;

		deviceCreateInfo.ppEnabledLayerNames = {}; //will use later for debugging
		deviceCreateInfo.pQueueCreateInfos = &queueCreateInfo;
		deviceCreateInfo.queueCreateInfoCount = 1;
		deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	


		 
		 VkResult result = vkCreateDevice(mPhysicalDevice, &deviceCreateInfo,nullptr, &mLogicalDevice);
		 assert(result == VK_SUCCESS);

		 vkGetDeviceQueue(mLogicalDevice,0,0,&graphicsQueue);
		
	}


	// !----------UTILITY FUNCTIONS----------!
	bool VkRenderSubSystem::checkPhysicalDevice(VkPhysicalDevice &device)
	{

		VkPhysicalDeviceProperties deviceProperties;
		VkPhysicalDeviceFeatures deviceFeatures;
		vkGetPhysicalDeviceProperties(device, &deviceProperties);
		vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

		return true;
	}






	// !----------CONSTRUCTORS/DESTRUCTORS----------!
	VkRenderSubSystem::VkRenderSubSystem()
	{
		initVulkan();
	}

	VkRenderSubSystem::~VkRenderSubSystem()
	{
		
		vkDestroyDevice(mLogicalDevice, nullptr);
		vkDestroyInstance(mVkInstance, nullptr);
		glfwDestroyWindow(mWindow);

		glfwTerminate();
	}

}