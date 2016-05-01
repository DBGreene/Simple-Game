#pragma once

#include "mesh.h"
#include "texture.h"
#include "player.h"

class Health
{
public:
	Health(Player* player);
	~Health();

	void Render();
protected:
private:
	void Bind(Texture* tex);
	Mesh _mesh1;
	Mesh _mesh2;
	Mesh _mesh3;

	Player* _player;

	Texture _texture;
	Texture _halfHeart;
	Texture _deadHeart;
};

