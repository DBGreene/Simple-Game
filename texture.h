#pragma once

#include <GL/glew.h>
#include <string>

class Texture
{
public:
	Texture();

	void Init(const std::string& filename);

	void Bind(unsigned int unit);

	void DelTexture();

	~Texture();
protected:
private:
	GLuint _texture;
};

