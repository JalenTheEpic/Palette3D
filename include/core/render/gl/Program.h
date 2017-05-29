/*
Palette3D
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_RENDER_GL_PROGRAM_
#define _CORE_RENDER_GL_PROGRAM_

#include <GL\glew.h>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <core\math\Math.h>
namespace Palette3D
{
	//vectors and matricies are F32
	enum class UniformType {Vec4, Vec3, Vec2, F32, I32, U32, Matrix3, Matrix4};

	
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
		inline void setUniform(GLchar * name, Matrix3 m) 
		{ 
			check();
			GLfloat mgl[9];
			size_t x = 0;
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					mgl[x] = m[j][i];
					x++;
				}
			}
			glUniformMatrix3fv(mUniforms[name], 1, GL_FALSE, mgl);
		};
		inline void setUniform(GLchar * name, Matrix4 m) 
		{
			check();
			glUniformMatrix4fv(mUniforms[name], 1, GL_FALSE, m.mMat);
		
		
		
		};


	private:
		static const Program * mspActive;
		GLuint mProg;
		std::map<GLchar *, GLint> mUniforms;
		

		

	};


}




#endif