#pragma once

#include <string>

#include "texture.h"
#include "mesh.h"
#include "transform.h"
#include "level.h"

class Player
{
public:
	Player(std::string texLocation);
	~Player();

	void Bind();
	void Render();
	void ChangeSprite(std::string location);
	void Collision(Transform* transform, int width, int height, Level* lev);

	bool collRight;
	bool collLeft;
	bool collUp;
	bool collDown;

protected:
private:
	Mesh _mesh;
	Texture _texture;

	std::string prevSprite;
	std::vector<std::string> exit;

	bool check = false;
	bool rWall;
	bool lWall;
	bool uWall;
	bool dWall;

	float health = 0.0f;

	enum
	{
		LEFT_IMG,
		LEFT_DAT,
		RIGHT_IMG,
		RIGHT_DAT,
		UP_IMG,
		UP_DAT,
		DOWN_IMG,
		DOWN_DAT
	};
};

