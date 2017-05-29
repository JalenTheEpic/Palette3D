#include <core\render\gl\glRenderSubsystem.h>

#define GLFW_DLL
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <core\render\gl\Program.h>
#include <core\render\gl\square.h>


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

		glEnable(GL_DEPTH_TEST);

		//Retrieves the size of the framebuffer of the window.
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);

		//Sets our viewport to that framebuffer size.
		glViewport(0, 0, width, height);

		//This allows us to handle inputs 
		glfwSetKeyCallback(window, key_callback);

		Program prog("..\\..\\Shaders\\test.vert","..\\..\\Shaders\\test.frag");

		prog.addUniform("ourTexture");
		prog.addUniform("transform");
		UnitSquare square;



		while (!glfwWindowShouldClose(window))
		{
			//Proccesses events in queue
			glfwPollEvents();

			

			//Draw phase
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			square.draw(prog);
			// Swap the buffers
			glfwSwapBuffers(window);
		}

		

		
	}

	GlRenderSubSystem::~GlRenderSubSystem()
	{
		
		glfwTerminate();
	}

	
}