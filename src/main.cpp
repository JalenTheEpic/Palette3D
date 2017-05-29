
#include <core\Core.h>

#include <iostream>

using namespace Palette3D;
int main() 
{
	
	
	//Palette3D::VkRenderSubSystem r;
	//r.debugRun();
	Vec4 v(4,4,4,4);
	Matrix4 m = Matrix4::IDENTITY;

	
	std::cout << m * v <<std::endl << std::endl;
	
	GlRenderSubSystem g;
	

	return 0;
}