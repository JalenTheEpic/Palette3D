
#include <core\Core.h>

#include <iostream>

using namespace Palette3D;
int main() 
{
	
	
	//Palette3D::VkRenderSubSystem r;
	//r.debugRun();
	Vec4 v(1,1,1,1);
	Matrix4 m = Matrix4::scale(.5,1,1)*Matrix4::translate(3,3,3);

	
	std::cout << m * v <<m <<std::endl << std::endl;
	while (1) {};
	//GlRenderSubSystem g;
	

	return 0;
}