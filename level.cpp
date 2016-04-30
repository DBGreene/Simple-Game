#include "level.h"

#include <iostream>

Level::Level(std::string texLocation)
{
	Vertex vertices[] = { Vertex(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(1.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f)),
		Vertex(glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f))
	};
	
	_mesh.Init(vertices, sizeof(vertices) / sizeof(vertices[0]));
	_tex.Init(texLocation);
}

void Level::ChangeLevel(std::string loc)
{
	_tex.DelTexture();
	_tex.Init(loc);
}

void Level::LoadLevel(std::string loc)
{
	exits = _reader.ReadFile(loc);
} 

Level::~Level()
{
}

void Level::Bind()
{
	_tex.Bind(0);
}

void Level::Render()
{
	_mesh.Draw();
}

std::vector<std::string> Level::GetExits()
{
	return exits;
}