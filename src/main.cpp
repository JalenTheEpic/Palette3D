
#include <core\Core.h>

#include <iostream>

using namespace Palette3D;
int main() 
{
	
	
	//Palette3D::VkRenderSubSystem r;
	//r.debugRun();
	Vec4 v(1,1,1,1);
	Matrix4 m = Matrix4::IDENTITY;
	
	std::cout << v <<std::endl << m<< std::endl;
	GlRenderSubSystem g;
	

	return 0;
}