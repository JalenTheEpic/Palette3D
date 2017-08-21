/*
Palette3D
Licensed under the terms of the MIT License (see LICENSE.txt)
*/

#ifndef _CORE_RENDER_GL_TEXTURE_
#define _CORE_RENDER_GL_TEXTURE_




#include <gl\glew.h>
#include <iostream>
namespace Palette3D {

	class GlTexture {
	private:
		GLuint mTex;
	public:
		GlTexture(GLchar * filename);
		~GlTexture();
		void bind() {
			//glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0); // set it manually << put that in program if we ever use multiple textures
			//glActiveTexture(GL_TEXTURE0);
			
			glBindTexture(GL_TEXTURE_2D, mTex); 
		}

	};



}



#endif