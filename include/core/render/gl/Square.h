#ifndef _CORE_RENDER_GL_SQUARE_
#define _CORE_RENDER_GL_SQUARE_
#include <GL\glew.h>
#include <core\math\Math.h>
#include <core\render\gl\Texture.h>
namespace Palette3D
{

	class UnitSquare
	{
	public:
		Vec3 pos = Vec3(0,0,0);
		GLuint VAO;
		GLuint VBO; //Vertex buffer object
		GLuint EBO;
		GlTexture tex = GlTexture("..\\..\\Media\\container.jpg");
		Matrix4 trans = Matrix4::translate(0,0,0);
		UnitSquare() 
		{

			//GLfloat vertices[] = {
			//	0.5f,  0.5f, 0.0f,  // Top Right
			//	0.5f, -0.5f, 0.0f,  // Bottom Right
			//	-0.5f, -0.5f, 0.0f,  // Bottom Left
			//	-0.5f,  0.5f, 0.0f   // Top Left 
			//};
			GLuint indices[] = {
				0, 1, 3,  // First Triangle
				1, 2, 3   // Second Triangle
			};

			GLfloat vertices[] = {
				// positions          // colors           // texture coords
				0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
				0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
				-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
				-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
			};
			//Creating a Vertex Array Object
			
			glGenVertexArrays(1, &VAO);


			//Generates a buffer and stores it in VBO
			glGenBuffers(1, &VBO);

			
			glGenBuffers(1, &EBO);


			//Bind VAO
			glBindVertexArray(VAO);


			//Specifies the type of the buffer
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			//copies data to buffer
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			/*
			Parameter 1: Layout location
			Parameter 2: Size of vertex attribute. We're sending Vec3's for now
			Parameter 3: Type of data
			Parameter 4: True means data will be normalized to be between -1-1
			Parameter 5: Stride. 0 means GL will figure it out.
			Parameter 5: Start offest

			*/
			
			//Vertex data
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
			//Enables Vertex arribute 0
			glEnableVertexAttribArray(0);
			
			//Color data
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8* sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
			//Enables Vertex arribute 0
			glEnableVertexAttribArray(1);

			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid*)(6 * sizeof(GLfloat)));
			glEnableVertexAttribArray(2);

			glBindBuffer(GL_ARRAY_BUFFER, 0);


			//unbind VAO
			glBindVertexArray(0);
		
		
		
		
		
		}



		void draw(Program & p)
		{
			p.use();
			p.setUniform("transform", trans);
			tex.bind();
			glBindVertexArray(VAO);
			trans *= Matrix4::rotation(1,1,1);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

		}
		~UnitSquare()
		{
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteBuffers(1, &EBO);

		}



	};



}

#endif