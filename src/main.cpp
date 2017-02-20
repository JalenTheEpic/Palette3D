#include <iostream>
#include <string>
#include <core\math\Matrix3.h>
int main()
{
	std::cout << "test" << std::endl;
	Palette3D::Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	std::cout << m* m <<std::endl;

	while (1)
	{
		;
	}

	return 0;
	
	
}