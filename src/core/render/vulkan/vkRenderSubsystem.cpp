#include <core\render\vulkan\vkRenderSubsystem.h>


namespace Palette3D {


	// !----------INIT FUNCTIONS----------!

	void VkRenderSubSystem::initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		mpWindow = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan window", nullptr, nullptr);
	}

	void VkRenderSubSystem::initVulkan() {


	}

	void VkRenderSubSystem::initVkInstance() {

		if (mEnableValidationLayers) {
			if (!checkValidationLayers()) {

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
		switch (vkCreateInstance(&createInfo, nullptr, &mVkInstance)) {
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

	void VkRenderSubSystem::initDebugCallback() {
		if (!mEnableValidationLayers) return;


		VkDebugReportCallbackCreateInfoEXT createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		createInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_INFORMATION_BIT_EXT;
		createInfo.pfnCallback = debugCallback;

		if (createDebugReportCallbackEXT(mVkInstance, &createInfo, nullptr, &mCallback) != VK_SUCCESS){

			THROW_EXCEPTION("failed to set up debug callback!", ExceptionType::Failure);

		}
	}

	void VkRenderSubSystem::choosePhysicalDevice(){
		//see how many vulkan supported devices we have
		U32 deviceCount = 0;
		VkResult result = vkEnumeratePhysicalDevices(mVkInstance, &deviceCount, nullptr);
		assert(result == VK_SUCCESS);
		assert(deviceCount >= 1);

		//gets handles to the physical devices supported by vulkan
		std::vector<VkPhysicalDevice> physicalDevices(deviceCount);
		result = vkEnumeratePhysicalDevices(mVkInstance, &deviceCount, physicalDevices.data());
		assert(result == VK_SUCCESS);



		for (const auto& device : physicalDevices){
			if (checkPhysicalDevice(device)){
				mPhysicalDevice = device;
				break;
			}
		}

		if (mPhysicalDevice == VK_NULL_HANDLE){
			THROW_EXCEPTION("failed to find a suitable physical device", ExceptionType::Failure);
		}
	}




	void VkRenderSubSystem::initLogicalDevice(){
#pragma region Queue_Create

		//Split into a function when more queues will be used
		//currently only enables the grapics queue
		U32 queueFamilyPropertyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyPropertyCount, nullptr);
		fprintf(stdout, "%d QueueFamilyPropertyCount(s)\n", queueFamilyPropertyCount);


		std::vector<VkQueueFamilyProperties> queueFamilyProps(queueFamilyPropertyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyPropertyCount, queueFamilyProps.data());

		U16 graphicsQueueIndex = 0;
		for (auto queue : queueFamilyProps){
			if (queue.queueFlags & VK_QUEUE_GRAPHICS_BIT){
				break;
			}
			graphicsQueueIndex++;
			if (graphicsQueueIndex > queueFamilyPropertyCount)
				THROW_EXCEPTION("NO GRAPHICS QUEUE FOUND", ExceptionType::IndexOutOfRange);
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




		VkResult result = vkCreateDevice(mPhysicalDevice, &deviceCreateInfo, nullptr, &mLogicalDevice);
		assert(result == VK_SUCCESS);

		vkGetDeviceQueue(mLogicalDevice, 0, 0, &mGraphicsQueue);

	}

	void VkRenderSubSystem::initSwapChain(){
		SwapChainSupportDetails swapChainSupport = querySwapChainSupport(mPhysicalDevice);

		VkSurfaceFormatKHR surfaceFormat = chooseSwapSurfaceFormat(swapChainSupport.formats);
		mSwapChainImageFormat = surfaceFormat.format;
		VkPresentModeKHR presentMode = chooseSwapPresentMode(swapChainSupport.presentModes);
		VkExtent2D mSwapChainExtent = chooseSwapExtent(swapChainSupport.capabilities);

		U32 imageCount = swapChainSupport.capabilities.minImageCount + 1;
		if (swapChainSupport.capabilities.maxImageCount > 0 && imageCount > swapChainSupport.capabilities.maxImageCount) {
			imageCount = swapChainSupport.capabilities.maxImageCount;
		}


		VkSwapchainCreateInfoKHR createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		createInfo.surface = mSurface;
		createInfo.minImageCount = imageCount;
		createInfo.imageFormat = surfaceFormat.format;
		createInfo.imageColorSpace = surfaceFormat.colorSpace;
		createInfo.imageExtent = mSwapChainExtent;
		createInfo.imageArrayLayers = 1;
		createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT; //VK_IMAGE_USAGE_TRANSFER_DST_BIT <<for post proccessing later


		//this probably won't work on amd cards 
		createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
		createInfo.queueFamilyIndexCount = 0; // Optional
		createInfo.pQueueFamilyIndices = nullptr; // Optional

		createInfo.preTransform = swapChainSupport.capabilities.currentTransform;
		createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;

		createInfo.presentMode = presentMode;
		createInfo.clipped = VK_TRUE;

		createInfo.oldSwapchain = VK_NULL_HANDLE;
		if (vkCreateSwapchainKHR(mLogicalDevice, &createInfo, nullptr, &mSwapChain) != VK_SUCCESS){
			throw std::runtime_error("failed to create swap chain!");
		}

		vkGetSwapchainImagesKHR(mLogicalDevice, mSwapChain, &imageCount, nullptr);
		mSwapChainImages.resize(imageCount);
		vkGetSwapchainImagesKHR(mLogicalDevice, mSwapChain, &imageCount, mSwapChainImages.data());
	}

	void VkRenderSubSystem::initVkSurface(){

		if (glfwCreateWindowSurface(mVkInstance, mpWindow, nullptr, &mSurface) != VK_SUCCESS){
			throw std::runtime_error("failed to create window surface!");
		}
		//VkBool32 supports = VK_TRUE;

		//also will only work for some computers
		//vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, 0, mSurface, &supports);

		/*if (supports == VK_FALSE)
		{
			THROW_EXCEPTION("No surface support", ExceptionType::Failure);
		}
		*/
	}

	void VkRenderSubSystem::bindWindow(){


	}

	std::vector<const char*> VkRenderSubSystem::getExtensions(){
		std::vector<const char*> extensions;

		U32 glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		for (U16 i = 0; i < glfwExtensionCount; i++) {
			extensions.push_back(glfwExtensions[i]);
		}

		if (mEnableValidationLayers) {
			extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
		}

		return extensions;
	}


	// !----------UTILITY FUNCTIONS----------!
	bool VkRenderSubSystem::checkPhysicalDevice(VkPhysicalDevice device) {

		VkPhysicalDeviceProperties deviceProperties;
		VkPhysicalDeviceFeatures deviceFeatures;
		vkGetPhysicalDeviceProperties(device, &deviceProperties);
		vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

		//TODO::FINISH THIS
		//I need to check the device to make sure it has support for everything we need
		//I already know that my gpu has what we need so I'll fninish this later when needed

		return true;
	}

	bool VkRenderSubSystem::checkValidationLayers() {

		U32 layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
		/*
		for (auto layer : availableLayers){
			std::cout << layer.layerName <<std::endl;

		}
		*/


		for (const char* layerName : mValidationLayers) {
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers) {
				if (strcmp(layerName, layerProperties.layerName) == 0) {
					layerFound = true;
					break;
				}
			}

			if (!layerFound) {
				return false;
			}
		}

		return true;

	}

	bool VkRenderSubSystem::checkDeviceExtensionSupport(VkPhysicalDevice device) {
		uint32_t extensionCount;
		vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

		std::vector<VkExtensionProperties> availableExtensions(extensionCount);
		vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

		std::set<std::string> requiredExtensions(mDeviceExtensions.begin(), mDeviceExtensions.end());

		for (const auto& extension : availableExtensions) {
			requiredExtensions.erase(extension.extensionName);
		}

		return requiredExtensions.empty();
	}

	SwapChainSupportDetails VkRenderSubSystem::querySwapChainSupport(VkPhysicalDevice device) {
		SwapChainSupportDetails details;
		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, mSurface, &details.capabilities);

		uint32_t formatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(device, mSurface, &formatCount, nullptr);

		if (formatCount != 0) {
			details.formats.resize(formatCount);
			vkGetPhysicalDeviceSurfaceFormatsKHR(device, mSurface, &formatCount, details.formats.data());
		}


		uint32_t presentModeCount;
		vkGetPhysicalDeviceSurfacePresentModesKHR(device, mSurface, &presentModeCount, nullptr);

		if (presentModeCount != 0) {
			details.presentModes.resize(presentModeCount);
			vkGetPhysicalDeviceSurfacePresentModesKHR(device, mSurface, &presentModeCount, details.presentModes.data());
		}
		return details;
	}

	VkSurfaceFormatKHR VkRenderSubSystem::chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats) {

		if (availableFormats.size() == 1 && availableFormats[0].format == VK_FORMAT_UNDEFINED) {
			return { VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR };
		}


		for (const auto& availableFormat : availableFormats) {
			if (availableFormat.format == VK_FORMAT_B8G8R8A8_UNORM && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
				return availableFormat;
			}
		}

		return availableFormats[0];
	}

	VkPresentModeKHR VkRenderSubSystem::chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes) {
		VkPresentModeKHR bestMode = VK_PRESENT_MODE_FIFO_KHR;

		for (const auto& availablePresentMode : availablePresentModes) {
			if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
				return availablePresentMode;
			}
			else if (availablePresentMode == VK_PRESENT_MODE_IMMEDIATE_KHR) {
				bestMode = availablePresentMode;
			}
		}

		return bestMode;
	}

	VkExtent2D VkRenderSubSystem::chooseSwapExtent(const VkSurfaceCapabilitiesKHR & capabilities) {
		if (capabilities.currentExtent.width != std::numeric_limits<U32>::max()) {
			return capabilities.currentExtent;
		}
		else {
			VkExtent2D actualExtent = { WIDTH, HEIGHT };

			actualExtent.width = std::max(capabilities.minImageExtent.width, std::min(capabilities.maxImageExtent.width, actualExtent.width));
			actualExtent.height = std::max(capabilities.minImageExtent.height, std::min(capabilities.maxImageExtent.height, actualExtent.height));

			return actualExtent;
		}
	}

	VKAPI_ATTR VkBool32 VKAPI_CALL VkRenderSubSystem::debugCallback(
		VkDebugReportFlagsEXT flags,
		VkDebugReportObjectTypeEXT objType,
		uint64_t obj,
		size_t location,
		int32_t code,
		const char * layerPrefix,
		const char * msg,
		void * userData) {
		std::cerr << "validation layer: " << msg << std::endl;
		return VK_FALSE;
	}

	VkResult VkRenderSubSystem::createDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDebugReportCallbackEXT * pCallback) {
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
	VkRenderSubSystem::VkRenderSubSystem() {
		initWindow();
		initVkInstance();
		initDebugCallback();

		initVkSurface();
		bindWindow();

		choosePhysicalDevice();
		initLogicalDevice();
		initSwapChain();


	}

	VkRenderSubSystem::~VkRenderSubSystem() {

		destroyDebugReportCallbackEXT(mVkInstance, mCallback, nullptr);
		vkDestroySwapchainKHR(mLogicalDevice, mSwapChain, nullptr);
		vkDestroyDevice(mLogicalDevice, nullptr);
		vkDestroySurfaceKHR(mVkInstance, mSurface, nullptr);
		vkDestroyInstance(mVkInstance, nullptr);
		glfwDestroyWindow(mpWindow);


		glfwTerminate();
	}

}