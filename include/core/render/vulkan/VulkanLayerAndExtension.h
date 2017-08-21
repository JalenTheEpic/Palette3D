#ifndef _CORE_RENDER_VULKAN_VULKANLAYERANDEXTENSION_
#define _CORE_RENDER_VULKAN_VULKANLAYERANDEXTENSION_
#include <vulkan\vulkan.h>
#include <vector>
#include <core\atomic\Types.h>
#include <debugging\Exception.h>
#include <assert.h>
namespace Palette3D {

	struct LayerProperties {
		VkLayerProperties properties;
		std::vector<VkExtensionProperties> extensions;
	}; 



	// Layers and corresponding extension list
	std::vector<LayerProperties> getInstanceLayerProperties();


	// Global extensions
	VkResult getExtensionProperties(LayerProperties & layerProps, VkPhysicalDevice * gpu = nullptr);


	// Device based extensions
	VkResult getDeviceExtensionsProperties(VkPhysicalDevice * gpu);


}


#endif // !_CORE_RENDER_VULKAN_VULKANLAYERANDEXTENSION_