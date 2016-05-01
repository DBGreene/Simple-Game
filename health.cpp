#include "health.h"

Health::Health(Player* player)
{
	_player = player;
	Vertex healthVert[] = { Vertex(glm::vec3(0.0166625f, 0.0166625f, 0.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.0166625f, -0.0166625f, 0.0f), glm::vec2(0.0f, 1.0f)),
		Vertex(glm::vec3(-0.0166625f, -0.0166625f, 0.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.0166625f, 0.0166625f, 0.0f), glm::vec2(1.0f, 0.0f))
	};

	Vertex healthVert2[] = { Vertex(glm::vec3(0.06665f, 0.0166625f, 0.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(0.06665f, -0.0166625f, 0.0f), glm::vec2(0.0f, 1.0f)),
		Vertex(glm::vec3(0.033325f, -0.0166625f, 0.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(0.033325f, 0.0166625f, 0.0f), glm::vec2(1.0f, 0.0f))
	};

	Vertex healthVert3[] = { Vertex(glm::vec3(-0.033325f, 0.0166625f, 0.0f), glm::vec2(0.0f, 0.0f)),
		Vertex(glm::vec3(-0.033325f, -0.0166625f, 0.0f), glm::vec2(0.0f, 1.0f)),
		Vertex(glm::vec3(-0.06665f, -0.0166625f, 0.0f), glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.06665f, 0.0166625f, 0.0f), glm::vec2(1.0f, 0.0f))
	};

	_mesh1.Init(healthVert, sizeof(healthVert) / sizeof(healthVert[0]));
	_mesh2.Init(healthVert2, sizeof(healthVert2) / sizeof(healthVert2[0]));
	_mesh3.Init(healthVert3, sizeof(healthVert3) / sizeof(healthVert3[0]));

	_texture.Init("./res/health/heart.png");
	_halfHeart.Init("./res/health/half_heart.png");
	_deadHeart.Init("./res/health/dead_heart.png");
}


Health::~Health()
{
	_texture.DelTexture();
	_halfHeart.DelTexture();
	_deadHeart.DelTexture();
}

void Health::Render()
{
	Bind(&_texture);
	if (_player->GetHealth() >= 6)
		_mesh3.Draw();
	if(_player->GetHealth() >= 4)
		_mesh1.Draw();
	if (_player->GetHealth() >= 2)
		_mesh2.Draw();

	Bind(&_halfHeart);
	if (_player->GetHealth() == 5)
		_mesh3.Draw();
	if (_player->GetHealth() == 3)
		_mesh1.Draw();
	if (_player->GetHealth() == 1)
		_mesh2.Draw();

	Bind(&_deadHeart);
	if (_player->GetHealth() < 5)
		_mesh3.Draw();
	if (_player->GetHealth() < 3)
		_mesh1.Draw();
	if (_player->GetHealth() < 1)
		_mesh2.Draw();
}

void Health::Bind(Texture* tex)
{
	tex->Bind(0);
}