#include "Player.h"

#include <iostream>
#include <glm/glm.hpp>

#include "mymaths.h"

Player::Player(std::string texLocation)
{
	Vertex vertices[] = { Vertex(glm::vec3(0.5f, 0.8f, 0.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.8f, 0.0f), glm::vec2(1.0f, 0.0f))
	};

	_mesh.Init(vertices, sizeof(vertices) / sizeof(vertices[0]));
	_texture.Init(texLocation);
}

Player::~Player()
{
}

void Player::Bind()
{
	_texture.Bind(0);
}

void Player::Render()
{
	_mesh.Draw();
}

void Player::ChangeSprite(std::string location)
{
	if (location != prevSprite)
	{
		_texture.DelTexture();
		_texture.Init(location);
	}
	prevSprite = location;
}

void Player::Collision(Transform* transform, int width, int height, Level* lev)
{
	if (!check)
	{
		for (int i = 0; i < lev->GetExits().size(); i++)
		{
			if (lev->GetExits()[i] == "wall")
			{
				if (i == 1)
					lWall = true;
				else if (i == 3)
					rWall = true;
				else if (i == 5)
					uWall = true;
				else if (i == 7)
					dWall = true;
			}
		}
		check = true;
	}
	if (((int)(((float)width / (float)height) * 10) / 10.0) <= transform->GetPos().x && !lWall)
	{
		lev->ChangeLevel(lev->GetExits()[LEFT_IMG]);
		lev->LoadLevel(lev->GetExits()[LEFT_DAT]);
		transform->GetPos().x = -1.3;
		check = false;
		rWall = false;
		lWall = false;
		uWall = false;
		dWall = false;
		collLeft = false;
		collRight = false;
	}

	else if (width / 2.0 * 0.0033325 <= transform->GetPos().x && lWall)
	{
		collLeft = true;
	}

	else if (width / 2.0 * 0.0033325 > transform->GetPos().x && lWall)
	{
		collLeft = false;
	}
	if (width / 2.0 * 0.0033325 <= transform->GetPos().x * -1 && !rWall)
	{
		lev->ChangeLevel(lev->GetExits()[RIGHT_IMG]);
		lev->LoadLevel(lev->GetExits()[RIGHT_DAT]);
		transform->GetPos().x = 1.3;
		check = false;
		rWall = false;
		lWall = false;
		uWall = false;
		dWall = false;
	}
	else if (width / 2.0 * 0.0033325 <= transform->GetPos().x * -1 && rWall)
	{
		collRight = true;
	}
	else if (width / 2.0 * 0.0033325 > transform->GetPos().x && rWall)
	{
		collRight = false;
	}

	if (0.33 <= transform->GetPos().y && !uWall)
	{
		lev->ChangeLevel(lev->GetExits()[UP_IMG]);
		lev->LoadLevel(lev->GetExits()[UP_DAT]);
		transform->GetPos().y = 0;
		check = false;
		rWall = false;
		lWall = false;
		uWall = false;
		dWall = false;
	}
	else if (0.33 <= transform->GetPos().y && uWall)
	{
		collUp = true;
	}
	else if (0.33 > transform->GetPos().y && uWall)
	{
		collUp = false;
	}
	if (height / 2.0 * 0.0033325 <= transform->GetPos().y * -1 && !dWall)
	{
		lev->ChangeLevel(lev->GetExits()[DOWN_IMG]);
		lev->LoadLevel(lev->GetExits()[DOWN_DAT]);
		transform->GetPos().y = 0;
		check = false;
		rWall = false;
		lWall = false;
		uWall = false;
		dWall = false;
	}
	else if ((height / 2.0 * 0.0033325) <= transform->GetPos().y + transform->GetScale().y * -1 && dWall)
	{
		collDown = true;
	}
	else if ((height / 2.0 * 0.0033325)> transform->GetPos().y + transform->GetScale().y * -1 && dWall)
	{
		collDown = false;
	}
}

float Player::GetHealth()
{
	return 0.0f;
}