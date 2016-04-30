#pragma once

#include <string>
#include <vector>

#include "mesh.h"
#include "texture.h"
#include "levelReader.h"

class Level
{
public:
	Level(std::string texLocation);
	~Level();

	void Bind();
	void Render();
	void ChangeLevel(std::string loc);
	void LoadLevel(std::string loc);
	std::vector<std::string> GetExits();

protected:
private:
	Mesh _mesh;
	Texture _tex;

	LevelReader _reader;

	std::vector<std::string> exits;
};

