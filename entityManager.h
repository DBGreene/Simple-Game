#pragma once

#include "transform.h"
#include "player.h"
#include <string>

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void Init(Transform* transform, Player* player);
	void Move(int dir);
	void UpdateCollisions(int width, int height, Level* lev);

protected:
private:
	Transform* _transform;
	Player* _player;

	void Animate(int dir);

	float GetX();
	float GetY();

	float _speed = 0.01f;

	int c = 0;
	int index = 0;
};

