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
		VkQueue mPresentQueue;
		VkSurfaceKHR mSurface;
		VkDebugReportCallbackEXT mCallback;

		const std::vector<const char*> mValidationLayers = {
			"VK_LAYER_LUNARG_standard_validation"
		};

		const std::vector<const char*> mDeviceExtensions = {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};
#ifdef NDEBUG
		const bool mEnableValidationLayers = false;
#else
		const bool mEnableValidationLayers = true;
#endif

		// !----------INIT FUNCTIONS----------!
		//Initializes Vulkan. 
		void initWindow();
		void initVulkan();
		void initVkInstance();
		void initDebugCallback();
		
		void choosePhysicalDevice();
		void initLogicalDevice();
		
		void initCommandBuffer();
		void initVkSurface();
		void bindWindow();

		std::vector<const char*> getExtensions();

		// !----------UTILITY FUNCTIONS----------!
		//checks if the device has the functionality we want
		//TODO:: FINISH THIS
		bool checkPhysicalDevice(VkPhysicalDevice &device);
		bool checkValidationLayers();


		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
			VkDebugReportFlagsEXT flags,
			VkDebugReportObjectTypeEXT objType,
			uint64_t obj,
			size_t location,
			int32_t code,
			const char* layerPrefix,
			const char* msg,
			void* userData);

		VkResult createDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
			const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);

		void destroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);
		

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
