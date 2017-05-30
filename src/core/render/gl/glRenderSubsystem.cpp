#include <core\render\gl\glRenderSubsystem.h>

#define GLFW_DLL
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <core\render\gl\Program.h>
#include <core\render\gl\square.h>
#include <core\render\gl\Cube.h>

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
		prog.addUniform("projection");
		prog.addUniform("view");
		prog.addUniform("model");

		Matrix4 p = Matrix4::perspective(45.0f, (float)800 / (float)600, 0.1f, 100.0f);
		Matrix4 v = Matrix4::translate(0,0,-3);
		prog.setUniform("projection", p);
		prog.setUniform("view", v);
		UnitSquare square;
		UnitCube cube;


		while (!glfwWindowShouldClose(window))
		{
			//Proccesses events in queue
			glfwPollEvents();

			

			//Draw phase
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			cube.draw(prog);
			// Swap the buffers
			glfwSwapBuffers(window);
		}

		

		
	}

	GlRenderSubSystem::~GlRenderSubSystem()
	{
		
		glfwTerminate();
	}

	
}