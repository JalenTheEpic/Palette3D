#ifndef _CORE_RENDER_GL_CUBE_
#define _CORE_RENDER_GL_CUBE_
#include <GL\glew.h>
#include <core\math\Math.h>
#include <core\render\gl\Texture.h>
#include <core\render\gl\Program.h>
namespace Palette3D
{

	class UnitCube
	{
	public:
		Vec3 pos = Vec3(0,0,0);
		GLuint VAO;
		GLuint VBO; //Vertex buffer object
		GLuint EBO;
		GlTexture tex = GlTexture("..\\..\\Media\\container.jpg");
		Matrix4 trans = Matrix4::translate(0,0,0);
		UnitCube() 
		{

			//GLfloat vertices[] = {
			//	0.5f,  0.5f, 0.0f,  // Top Right
			//	0.5f, -0.5f, 0.0f,  // Bottom Right
			//	-0.5f, -0.5f, 0.0f,  // Bottom Left
			//	-0.5f,  0.5f, 0.0f   // Top Left 
			//};
			

			float vertices[] = {
				-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
				0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
				0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
				0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
				0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
				0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
				-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
				-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
				-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

				0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
				0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
				0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
				0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
				0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
				0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
				-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
				-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
				0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
				0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
				0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
				-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
				-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
			};
			//Creating a Vertex Array Object
			
			glGenVertexArrays(1, &VAO);


			//Generates a buffer and stores it in VBO
			glGenBuffers(1, &VBO);

			
			


			//Bind VAO
			glBindVertexArray(VAO);


			//Specifies the type of the buffer
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			//copies data to buffer
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


			/*
			Parameter 1: Layout location
			Parameter 2: Size of vertex attribute. We're sending Vec3's for now
			Parameter 3: Type of data
			Parameter 4: True means data will be normalized to be between -1-1
			Parameter 5: Stride. 0 means GL will figure it out.
			Parameter 6: Start offest

			*/
			
			//Vertex data
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
			//Enables Vertex arribute 0
			glEnableVertexAttribArray(0);
			
			//Color data
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5* sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
			//Enables Vertex arribute 0
			glEnableVertexAttribArray(1);


			glBindBuffer(GL_ARRAY_BUFFER, 0);


			//unbind VAO
			glBindVertexArray(0);
		
		
		
		
		
		}



		void draw(Program & p)
		{
			p.use();
			p.setUniform("transform", trans);
			p.setUniform("model", Matrix4::IDENTITY);
			tex.bind();
			glBindVertexArray(VAO);
			trans *= Matrix4::rotation(1,1,1);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

		}
		~UnitCube()
		{
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			

		}



	};



}

#endif