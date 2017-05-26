/*
Palette3D
Copyright (c) 2017 Jalen Cureton
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_RENDER_GL_PROGRAM_
#define _CORE_RENDER_GL_PROGRAM_
#include <GL\glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
namespace Palette3D
{

	class Program


	{
	public:
		Program(std::string vsloc, std::string fsloc);
		~Program();

		void use();

	private:
		GLuint mProg;


		

	};


}




#endif