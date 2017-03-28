#include <iostream>
#include <string>
#include <core\core.h>
int main()
{
	std::cout << "test" << std::endl;
	Palette3D::Matrix3 m(1, 2, 3, 
						 4, 5, 6, 
						 7, 8, 9);

	Palette3D::Matrix3 m2(6, 24.5, 120,
						  17, 42, 66,
						  .3f, 0, 9);

	Palette3D::Matrix4 m4( 8,  11, 2,  8,
						   0,  -7, 2, -1,
						  -3,  -7, 2,  1,
						   1,   1, 2,  4);
	
	int i = 0;
	m += m;
	Palette3D::Vec2 v(3.f,4.f);

	Palette3D::Vec3 v2= Palette3D::Vec3(v);
	
	std::cout <<m4.determinant() << std::endl;
	while (1)
	{
		;
	}

	return 0;
	
	
}