#ifndef _CORE_RENDER_GL_SQUARE_
#define _CORE_RENDER_GL_SQUARE_
#include <GL\glew.h>
#include <core\math\Math.h>
namespace Palette3D
{

	class UnitSquare
	{

		Vec3 pos = Vec3(0,0,0);
		UnitSquare() 
		{

			GLfloat vertices[] = {
				0.5f,  0.5f, 0.0f,  // Top Right
				0.5f, -0.5f, 0.0f,  // Bottom Right
				-0.5f, -0.5f, 0.0f,  // Bottom Left
				-0.5f,  0.5f, 0.0f   // Top Left 
			};
			GLuint indices[] = {
				0, 1, 3,  // First Triangle
				1, 2, 3   // Second Triangle
			};


			//Creating a Vertex Array Object
			GLuint VAO;
			glGenVertexArrays(1, &VAO);


			GLuint VBO; //Vertex buffer object
						//Generates a buffer and stores it in VBO
			glGenBuffers(1, &VBO);

			GLuint EBO;
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
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
			//Enables Vertex arribute 0
			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);


			//unbind VAO
			glBindVertexArray(0);
		
		
		
		
		
		}



		draw()
		{
			glBindVertexArray(VAO);

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