#include <core\render\gl\glRenderSubsystem.h>
#define STB_IMAGE_IMPLEMENTATION
#include <depend\stb_image.h>
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


namespace Palette3D
{
	GlRenderSubSystem::GlRenderSubSystem()
	{
		if (!glfwInit())
		{
			//error
		}

		//GL setup
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		//Making the window
		GLFWwindow* window = glfwCreateWindow(800, 600, "Palette3D", nullptr, nullptr);
		if (window == nullptr)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		//Makes the context of the specified window current for the calling thread.
		glfwMakeContextCurrent(window);

		//This will allow us to use experimental GL features
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			//error
		}

		//Retrieves the size of the framebuffer of the window.
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);

		//Sets our viewport to that framebuffer size.
		glViewport(0, 0, width, height);

		//This allows us to handle inputs 
		glfwSetKeyCallback(window, key_callback);

		Program prog("..\\..\\Shaders\\test.vert","..\\..\\Shaders\\test.frag");

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
		








		//Texture stuff
		stbi_io_callbacks





		while (!glfwWindowShouldClose(window))
		{
			//Proccesses events in queue
			glfwPollEvents();

			

			//Draw phase
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			
			prog.use();
			glBindVertexArray(VAO);
			
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			// Swap the buffers
			glfwSwapBuffers(window);
		}

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);

		
	}

	GlRenderSubSystem::~GlRenderSubSystem()
	{
		
		glfwTerminate();
	}

	
}