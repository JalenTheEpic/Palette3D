
#include <core\Core.h>

#include <iostream>

int main() {
	
	


	Palette3D::VkRenderSubSystem renderer;

	Palette3D::Matrix4 matrix;
	Palette3D::Vec4 vec;
	auto test = matrix * vec;

	while (!glfwWindowShouldClose(renderer.mWindow)) {
		glfwPollEvents();
	}



	return 0;
}