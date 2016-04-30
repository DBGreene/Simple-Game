#include "display.h"

#include "Error.h"

Display::Display(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_width = width;
	_height = height;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	_glContext = SDL_GL_CreateContext(_window);

	GLenum status = glewInit();

	if (status != GLEW_OK)
		fatalError("Failed to initialize GLEW!");

	_isRunning = true;
}


Display::~Display()
{
}

bool Display::IsRunning()
{
	return _isRunning;
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

SDL_Window* Display::GetWindow()
{
	return _window;
}

SDL_GLContext Display::GetContext()
{
	return _glContext;
}

int Display::GetWidth()
{
	return _width;
}

int Display::GetHeight()
{
	return _height;
}