#include "entityManager.h"

#include <iostream>

#include "level.h"

EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

void EntityManager::Init(Transform* transform, Player* player)
{
	_transform = transform;
	_player = player;
}

void EntityManager::Move(int dir)
{
	if (dir == 0)
		_transform->GetPos().y += _speed;
	if (dir == 1)
	{
		_transform->GetPos().x -= _speed;
		Animate(dir);
	}
	if (dir == 2)
		_transform->GetPos().y -= _speed;
	if (dir == 3)
	{
		_transform->GetPos().x += _speed;
		Animate(dir);
	}
		
}

float EntityManager::GetX()
{
	return _transform->GetPos().x;
}

float EntityManager::GetY()
{
	return _transform->GetPos().y;
}

void EntityManager::UpdateCollisions(int width, int height, Level* lev)
{
	_player->Collision(_transform, width, height, lev);
}

void EntityManager::Animate(int dir)
{
	if (dir == 1 && c == 15 && index == 0)
	{
		_player->ChangeSprite("./res/player/steven_right1.png");
		c = 0;
		index++;
	}
	else if (dir == 1 && c == 15 && index == 1)
	{
		_player->ChangeSprite("./res/player/steven_right2.png");
		c = 0;
		index--;
	}
	else if (dir == 3 && c == 15 && index == 0)
	{
		_player->ChangeSprite("./res/player/steven_left1.png");
		c = 0;
		index++;
	}
	else if (dir == 3 && c == 15 && index == 1)
	{
		_player->ChangeSprite("./res/player/steven_left2.png");
		c = 0;
		index--;
	}
	c++;
}
