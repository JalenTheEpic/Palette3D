#include <iostream>
#include <string>
#include <core\math\Matrix3.h>
int main()
{
	std::cout << "test" << std::endl;
	Palette3D::Matrix3 m(1, 2, 3, 
						 4, 5, 6, 
						 7, 8, 9);

	Palette3D::Matrix3 m2(6, 24.5, 120,
						 17, 42, 66,
						 .3f, 0, 9);
	
	int i = 0;
	m += m;
	std::cout << m << std::endl;

	while (1)
	{
		;
	}

	return 0;
	
	
}