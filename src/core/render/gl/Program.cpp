#include <core\render\gl\Program.h>

namespace Palette3D
{

	
	const Program * Program::mspActive = nullptr;

	Program::Program(std::string vsloc, std::string fsloc)
	{
		
		
		std::string vSource, fSource; // will store code here
		std::ifstream vsFile, fsFile;
		// ensures ifstream objects can throw exceptions:
		vsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		
		try
		{
			vsFile.open(vsloc);
			fsFile.open(fsloc);

			std::stringstream vShaderStream, fShaderStream;
			// Read file's buffer contents into streams
			vShaderStream << vsFile.rdbuf();
			fShaderStream << fsFile.rdbuf();
			// close file handlers
			vsFile.close();
			fsFile.close();

			vSource = vShaderStream.str();
			fSource = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n" << e.what()<< std::endl;
		}
		
		
		const GLchar* vs = vSource.c_str();
		const GLchar* fs = fSource.c_str();
		
		

		GLuint vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vs, NULL);
		glCompileShader(vertexShader);
		GLint success;
		GLchar log[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, log);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << log << std::endl;
		}


		GLuint fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fs, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, log);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << log << std::endl;
		}

		//Making a program to link compiled shaders
		
		mProg = glCreateProgram();
		glAttachShader(mProg, vertexShader);
		glAttachShader(mProg, fragmentShader);
		glLinkProgram(mProg);
		glGetProgramiv(mProg, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mProg, 512, NULL, log);
			std::cout << "ERROR::SHADER::LINKING::FAILED\n" << log << std::endl;
		}



		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	Program::~Program()
	{
		glDeleteProgram(mProg);
	}

	void Program::use() const
	{
		mspActive = this;
		glUseProgram(mProg);
	}

	void Program::addUniform(GLchar * name, UniformType typ)
	{
		mUniforms[name] = glGetUniformLocation(mProg, name);
	}

	

}