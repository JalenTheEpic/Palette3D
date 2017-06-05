#include <core\render\gl\glRenderSubsystem.h>
#include <time.h>
#include <vector>
#include <game\camera\Camera.h>
#include <window\WindowManager.h>
#include <input\InputManager.h>


namespace Palette3D
{
	GlRenderSubSystem::GlRenderSubSystem()
	{
		WindowManager *  w = new WindowManager(800,600);
		InputManager * im = new InputManager();
		if (!im)
			std::cout << "Error" << std::endl;
		
		//This will allow us to use experimental GL features
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			//error
		}

		glEnable(GL_DEPTH_TEST);

		

		//This allows us to handle inputs 
		

		Program prog("..\\..\\Shaders\\test.vert","..\\..\\Shaders\\test.frag");

		prog.addUniform("ourTexture");
		prog.addUniform("projection");
		prog.addUniform("view");
		prog.addUniform("model");

		

		
		Matrix4 p = Matrix4::perspective(45.0f, (F32)800 / (F32)600, 0.1f, 100.0f);
		prog.setUniform("projection", p);


		Camera c(Vec3(0,0,10));
		prog.setUniform("view", c.lookAt());


		UnitSquare square;
		UnitCube cube;
		UnitCube cube2;
		UnitCube cube3;
		UnitCube cube4;
		
		cube.pos = Vec3(-3,0,-10);
		cube2.pos = Vec3(-1, 0, -10);
		cube3.pos = Vec3(1, 0, -10);
		cube4.pos = Vec3(3, 0, -10);

		
		float radius = 10.0f;
		

		F32 dt = 0, prevTime= 0, currentTime = 0;
		
		while (!glfwWindowShouldClose(WINDOW_MANAGER->getWindowPtr()))
		{
			
			// Calculate delta time
			currentTime = glfwGetTime();
			dt = currentTime - prevTime;
			
			prevTime = currentTime;
			//Proccesses events in queue
			INPUT_MANAGER->update();

			
		
			if (INPUT_MANAGER->getKey(GLFW_KEY_W))
				cube.pos -= Vec3(0, 0, 2 * dt);
			if (INPUT_MANAGER->getKey(GLFW_KEY_S))
				cube.pos += Vec3(0, 0, 2 * dt);
			if (INPUT_MANAGER->getKey(GLFW_KEY_A))
				cube.pos -= Vec3(2*dt, 0, 0);
			if (INPUT_MANAGER->getKey(GLFW_KEY_D))
				cube.pos += Vec3(2*dt, 0, 0);

			if (INPUT_MANAGER->getKey(GLFW_KEY_E))
				cube.pos -= Vec3(0, 2*dt, 0);
			if (INPUT_MANAGER->getKey(GLFW_KEY_Q))
				cube.pos += Vec3(0, 2 * dt, 0);


			c.mPosition.x = sin(glfwGetTime()) * radius;
			c.mPosition.z = cos(glfwGetTime()) * radius;
			prog.setUniform("view", c.getView());
			//std::cout << cube.pos << std::endl;


			
			
			//Draw phase
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			


			cube.update(dt);
			cube.draw(prog);

			cube2.update(-dt);
			cube2.draw(prog);

			cube3.update(dt);
			cube3.draw(prog);

			cube4.update(-dt);
			cube4.draw(prog);
			// Swap the buffers
			glfwSwapBuffers(WINDOW_MANAGER->getWindowPtr());
		
		}

		

		
	}

	GlRenderSubSystem::~GlRenderSubSystem()
	{
		
		glfwTerminate();
	}

	
}