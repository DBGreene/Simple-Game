#pragma once

#include <GL/glew.h>
#include <string>

#include "transform.h"
#include "camera.h"

class Shader
{
public:
	Shader(const std::string filename);
	~Shader();

	void Bind();
	void Update(const Transform& transform, Camera& camera);
protected:
private:
	static const unsigned int NUM_SHADERS = 2;

	GLuint CreateShader(const std::string& text, GLenum shaderType);
	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint _program;
	GLuint _shaders[NUM_SHADERS];
	GLuint _uniforms[NUM_UNIFORMS];
};

