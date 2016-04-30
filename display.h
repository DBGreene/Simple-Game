#include <SDL2/SDL.h>
#include <string>
#include <GL/glew.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	~Display();

	SDL_Window* GetWindow();
	SDL_GLContext GetContext();

	bool IsRunning();
	void Clear(float r, float g, float b, float a);
	int GetWidth();
	int GetHeight();

protected:
private:
	SDL_Window* _window;
	SDL_GLContext _glContext;

	bool _isRunning;

	int _width;
	int _height;
};
