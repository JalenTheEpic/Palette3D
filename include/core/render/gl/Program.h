/*
Palette3D
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_RENDER_GL_GLPROGRAM_
#define _CORE_RENDER_GL_GLPROGRAM_

#include <GL\glew.h>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <core\math\Math.h>
namespace Palette3D
{

	class Program
	{
	public:
		Program(std::string vsloc, std::string fsloc);
		~Program();

		void use() const;
		void addUniform(GLchar * name);
		
		
		
		
		
		inline void check() {if (mspActive != this) use();}
		inline void setUniform(GLchar * name, Vec2 &v) { check(); glUniform2f(mUniforms[name], v.x, v.y); };
		inline void setUniform(GLchar * name, Vec3 &v) { check(); glUniform3f(mUniforms[name], v.x, v.y, v.z); };
		inline void setUniform(GLchar * name, Vec4 &v) { check(); glUniform4f(mUniforms[name], v.x, v.y, v.z, v.w); };
		inline void setUniform(GLchar * name, F32 n) { check(); glUniform1f(mUniforms[name], n); };
		inline void setUniform(GLchar * name, I32 n) { check(); glUniform1i(mUniforms[name], n); };
		inline void setUniform(GLchar * name, U32 n) { check(); glUniform1ui(mUniforms[name], n); };
		void setUniform(GLchar * name, Matrix3 m);
		void setUniform(GLchar * name, Matrix4 m);


	private:
		static const Program * mspActive;
		GLuint mProg;
		std::map<GLchar *, GLint> mUniforms;
		

		

	};


}




#endif