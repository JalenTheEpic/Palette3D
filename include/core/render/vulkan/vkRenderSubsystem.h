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
#include <set>
#include <algorithm>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define	WIDTH 800
#define HEIGHT 600
namespace Palette3D {

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	struct QueueFamilyIndices {
		I32 graphicsFamily = -1;
		I32 presentFamily = -1;

		bool isComplete() {
			return graphicsFamily >= 0 && presentFamily >= 0;
		}
	};


	class VkRenderSubSystem {
	private:
		
		VkInstance mVkInstance;
		VkPhysicalDevice mPhysicalDevice;
		VkDevice mLogicalDevice;
		VkQueue mGraphicsQueue;
		VkQueue mPresentQueue;
		VkSurfaceKHR mSurface;
		VkDebugReportCallbackEXT mCallback;
		VkSwapchainKHR mSwapChain;
		
		std::vector<VkImage> mSwapChainImages;
		VkFormat mSwapChainImageFormat;
		VkExtent2D mSwapChainExtent;


		//SwapChainSupportDetails mSwapChainDetails;

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
		

		void initSwapChain();

		void initCommandBuffer();
		void initVkSurface();
		void bindWindow();



		std::vector<const char*> getExtensions();

		// !----------UTILITY FUNCTIONS----------!
	
		bool checkPhysicalDevice(VkPhysicalDevice device);
		bool checkValidationLayers();
		bool checkDeviceExtensionSupport(VkPhysicalDevice device);
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
			VkDebugReportFlagsEXT flags,
			VkDebugReportObjectTypeEXT objType,
			U64 obj,
			size_t location,
			I32 code,
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
		void debugRun(){
			while (!glfwWindowShouldClose(mpWindow)) {
				glfwPollEvents();
			}

		};
		

	};



	
}

#endif // !_CORE_RENDER_VKRENDERSUBSYSTEM_
