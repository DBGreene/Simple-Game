#include "InputManager.h"

#include <iostream>
#include "level.h"

InputManager::InputManager(SDL_Window* window, SDL_GLContext glContext, Transform* transform, Player* player, bool running)
{
	_window = window;
	_glContext = glContext;
	_isRunning = running;

	_player = player;

	_entityManager.Init(transform, player);
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
	SDL_GL_SwapWindow(_window);
}

void InputManager::RegisterInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		if (evnt.type == SDL_QUIT)
		{
			SDL_GL_DeleteContext(_glContext);
			SDL_DestroyWindow(_window);
			SDL_Quit();
			_isRunning = false;
		}
		if (evnt.type == SDL_KEYDOWN)
		{
			if (evnt.key.keysym.sym == SDLK_w)
			{
				_player->ChangeSprite("./res/player/steven_back.png");
				_up = true;
			}
			if (evnt.key.keysym.sym == SDLK_d)
			{
				_right = true;
			}
			if (evnt.key.keysym.sym == SDLK_s)
			{
				_player->ChangeSprite("./res/player/steven.png");
				_down = true;
			}
			if (evnt.key.keysym.sym == SDLK_a)
			{
				_left = true;
			}
			if (evnt.key.keysym.sym == SDLK_q)
			{
				_player->SetHealth(_player->GetHealth() - 1);
			}
		}
			if (evnt.type == SDL_KEYUP)
			{
				if (evnt.key.keysym.sym == SDLK_w)
				{
					_up = false;
					if (_right) _player->ChangeSprite("./res/player/steven_right.png");
					if (_down) _player->ChangeSprite("./res/player/steven.png");
					if (_left) _player->ChangeSprite("./res/player/steven_left.png");
				}
				if (evnt.key.keysym.sym == SDLK_d)
				{
					_right = false;
					if (_up) _player->ChangeSprite("./res/player/steven_back.png");
					if (_down) _player->ChangeSprite("./res/player/steven.png");
					if (_left) _player->ChangeSprite("./res/player/steven_left.png");
				}
				if (evnt.key.keysym.sym == SDLK_s)
				{
					_down = false;
					if (_up) _player->ChangeSprite("./res/player/steven_back.png");
					if (_right) _player->ChangeSprite("./res/player/steven_right.png");
					if (_left) _player->ChangeSprite("./res/player/steven_left.png");
				}
				if (evnt.key.keysym.sym == SDLK_a)
				{
					_left = false;
					if (_up) _player->ChangeSprite("./res/player/steven_back.png");
					if (_right) _player->ChangeSprite("./res/player/steven_right.png");
					if (_down) _player->ChangeSprite("./res/player/steven.png");
				}	
			}
	}
	if (_up && !_player->collUp)
	{
		_entityManager.Move(0);
	}
	
	if (_right && !_player->collRight)
	{
		_entityManager.Move(1);
	}
	
	if (_down && !_player->collDown)
	{
		_entityManager.Move(2);
	}
	
	if (_left && !_player->collLeft)
	{
		_entityManager.Move(3);
	}

	if (!_up && !_right && !_down && !_left)
	{
		if (count == 100)
		{
			if (c == 0)
			{
				_player->ChangeSprite("./res/player/steven_idle.png");
				c = 1;
			}
				
			else
			{
				_player->ChangeSprite("./res/player/steven.png");
				c = 0;
			}
				
			count = 0;
		}
		count++;
	}
}

bool InputManager::IsRunning()
{
	return _isRunning;
}

void InputManager::UpdateCollision(int width, int height, Level* lev)
{
	_entityManager.UpdateCollisions(width, height, lev);
}
