#pragma once

#include <SDL2/SDL.h>
#include "entityManager.h"
#include "player.h"

class InputManager
{
public:
	InputManager(SDL_Window* window, SDL_GLContext glContext, Transform* transform, Player* player, bool running);
	~InputManager();

	void Update();
	void RegisterInput();
	bool IsRunning();
	void UpdateCollision(int width, int height, Level* lev);

protected:
private:
	SDL_Window* _window;
	SDL_GLContext _glContext;

	Player* _player;

	EntityManager _entityManager;

	bool _isRunning;
	bool _up;
	bool _right;
	bool _down;
	bool _left;
	bool _spriteUp;
	bool _spriteRight;
	bool _spriteDown;
	bool _spriteLeft;
	bool _collRight;
	bool _collLeft;
	int count = 0;
	int c = 0;
};

