
#include <core\Core.h>

#include <iostream>

using namespace Palette3D;
int main() 
{
	
	
	//Palette3D::VkRenderSubSystem r;
	//r.debugRun();
	Matrix4 m(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
	

	std::cout << m.transpose();

	GlRenderSubSystem g;
	

	return 0;
}