#include <core\render\vulkan\vkRenderSubsystem.h>


namespace Palette3D
{


	// !----------INIT FUNCTIONS----------!

	void VkRenderSubSystem::initWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		mpWindow = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
	}

	void VkRenderSubSystem::initVulkan()
	{


	}

	void VkRenderSubSystem::initVkInstance()
	{

		if (mEnableValidationLayers)
		{
			if (!checkValidationLayers())
			{

				THROW_EXCEPTION("One or more validation layers not supported on machine. \n"
					"Install newest lunarSDK for validation layers please ", ExceptionType::ArgumentException);

			}

		}


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
/*
#if NDEBUG

#else

		U32 extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		std::vector<VkExtensionProperties> ext(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, ext.data());
		std::cout << "available extensions:" << std::endl;

		for (const auto& extension : ext) {
			std::cout << "\t" << extension.extensionName << std::endl;
		}
#endif
*/

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
		std::vector<const char*> extensions = getExtensions();
		createInfo.enabledExtensionCount = static_cast<U32>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();


		//end getting extensions

		if (mEnableValidationLayers) {
			createInfo.enabledLayerCount = static_cast<uint32_t>(mValidationLayers.size());
			createInfo.ppEnabledLayerNames = mValidationLayers.data();
		}
		else {
			createInfo.enabledLayerCount = 0;
		}




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

	void VkRenderSubSystem::initDebugCallback()
	{
		if (!mEnableValidationLayers) return;


		VkDebugReportCallbackCreateInfoEXT createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		createInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_INFORMATION_BIT_EXT;
		createInfo.pfnCallback = debugCallback;

		if (createDebugReportCallbackEXT(mVkInstance, &createInfo, nullptr, &mCallback) != VK_SUCCESS) 
		{

			THROW_EXCEPTION("failed to set up debug callback!", ExceptionType::Failure);
			
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
		F32 priority = 1.f;

		//Creating a single graphics queue family
		VkDeviceQueueCreateInfo queueCreateInfo = {};
		queueCreateInfo.flags = 0;
		queueCreateInfo.pNext = nullptr;
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.queueFamilyIndex = graphicsQueueIndex;
		queueCreateInfo.queueCount = 1;
		//we need to make a present queue later but for now since my card
		//has it all in the same queue family I'm not gonna do all that
		
		queueCreateInfo.pQueuePriorities = &priority;
#pragma endregion

#pragma region REVISIT

		//COME BACK TO ME WHEN WE DO CRAZY STUFF
		VkPhysicalDeviceFeatures deviceFeatures = {};

#pragma endregion

		VkDeviceCreateInfo deviceCreateInfo = {};
		
		//deviceCreateInfo.enabledLayerCount = 0;
		deviceCreateInfo.flags = 0;
		deviceCreateInfo.pEnabledFeatures = &deviceFeatures; //ptr to a VkPhysicalDeviceFeatures struct
		deviceCreateInfo.pNext = nullptr;

		deviceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(mDeviceExtensions.size());
		deviceCreateInfo.ppEnabledExtensionNames = mDeviceExtensions.data();
		deviceCreateInfo.pQueueCreateInfos = &queueCreateInfo;
		deviceCreateInfo.queueCreateInfoCount = 1;
		deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	


		 
		 VkResult result = vkCreateDevice(mPhysicalDevice, &deviceCreateInfo,nullptr, &mLogicalDevice);
		 assert(result == VK_SUCCESS);

		 vkGetDeviceQueue(mLogicalDevice,0,0,&mGraphicsQueue);
		
	}

	void VkRenderSubSystem::initVkSurface()
	{
		if (glfwCreateWindowSurface(mVkInstance, mpWindow, nullptr, &mSurface) != VK_SUCCESS) 
		{
			throw std::runtime_error("failed to create window surface!");
		}
	}

	void VkRenderSubSystem::bindWindow()
	{


	


	}

	std::vector<const char*> VkRenderSubSystem::getExtensions()
	{
		std::vector<const char*> extensions;

		U32 glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		for ( U16 i = 0; i < glfwExtensionCount; i++) {
			extensions.push_back(glfwExtensions[i]);
		}

		if (mEnableValidationLayers) {
			extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
		}

		return extensions;
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

	bool VkRenderSubSystem::checkValidationLayers()
	{

		U32 layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
		/*
		for (auto layer : availableLayers)
		{
			std::cout << layer.layerName <<std::endl;

		}
		*/
		

		for (const char* layerName : mValidationLayers)
		{
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers) 
			{
				if (strcmp(layerName, layerProperties.layerName) == 0) 
				{
					layerFound = true;
					break;
				}
			}

			if (!layerFound) 
			{
				return false;
			}
		}

		return true;

	}

	VKAPI_ATTR VkBool32 VKAPI_CALL VkRenderSubSystem::debugCallback(
		VkDebugReportFlagsEXT flags, 
		VkDebugReportObjectTypeEXT objType, 
		uint64_t obj, 
		size_t location, 
		int32_t code, 
		const char * layerPrefix, 
		const char * msg, 
		void * userData)
	{
		std::cerr << "validation layer: " << msg << std::endl;
		return VK_FALSE;
	}

	VkResult VkRenderSubSystem::createDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDebugReportCallbackEXT * pCallback)
	{
		auto func = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
		if (func != nullptr) {
			return func(instance, pCreateInfo, pAllocator, pCallback);
		}
		else {
			return VK_ERROR_EXTENSION_NOT_PRESENT;
		}
	}

	void VkRenderSubSystem::destroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks * pAllocator)
	{
		auto func = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
		if (func != nullptr) {
			func(instance, callback, pAllocator);
		}
	}






	// !----------CONSTRUCTORS/DESTRUCTORS----------!
	VkRenderSubSystem::VkRenderSubSystem()
	{
		initWindow();
		initVkInstance();
		initDebugCallback();
		
		initVkSurface();
		bindWindow();

		choosePhysicalDevice();
		initLogicalDevice();
	}

	VkRenderSubSystem::~VkRenderSubSystem()
	{
		
		destroyDebugReportCallbackEXT(mVkInstance, mCallback, nullptr);
		vkDestroyDevice(mLogicalDevice, nullptr);
		vkDestroySurfaceKHR(mVkInstance, mSurface, nullptr);
		vkDestroyInstance(mVkInstance, nullptr);
		glfwDestroyWindow(mpWindow);


		while (1) {}
		glfwTerminate();
	}

}