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
	void BindHealth();
	void Render();
	void RenderHealth();
	void ChangeSprite(std::string location);
	void Collision(Transform* transform, int width, int height, Level* lev);

	void SetHealth(float health);
	float GetHealth();

	bool collRight;
	bool collLeft;
	bool collUp;
	bool collDown;

protected:
private:
	Mesh _mesh;
	Mesh _heMesh;
	Texture _texture;
	Texture _heTexture;

	std::string prevSprite;
	std::vector<std::string> exit;

	bool check = false;
	bool rWall;
	bool lWall;
	bool uWall;
	bool dWall;

	float health = 6.0f;

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

