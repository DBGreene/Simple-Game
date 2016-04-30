#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include <iostream>

Texture::Texture()
{
	
}

Texture::~Texture()
{
	glDeleteTextures(1, &_texture);
}

void Texture::Init(const std::string& filename)
{
	int width, height, numComponents;
	unsigned char* data = stbi_load(filename.c_str(), &width, &height, &numComponents, 4);
	if (data == NULL)
		std::cerr << "Unable to load texture: " << filename << std::endl;

	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);
}

void Texture::Bind(unsigned int unit)
{
	glBindTexture(GL_TEXTURE_2D, _texture);
}

void Texture::DelTexture()
{
	glDeleteTextures(1, &_texture);
}