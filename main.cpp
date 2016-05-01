#include <GL/glew.h>
#include <glm/glm.hpp>

#include <iostream>
#include <Windows.h>

#include "display.h"
#include "inputManager.h"
#include "entityManager.h"
#include "shader.h"
#include "camera.h"
#include "player.h"
#include "level.h"
#include "levelReader.h"
#include "health.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char** argv)
{
	Display display(WIDTH, HEIGHT, "OpenGL");

	Player player("./res/player/steven.png");

	Shader shader("./res/basicShader");
	Transform transform;
	Transform transform2;
	Transform healthTransform;

	InputManager manager(display.GetWindow(), display.GetContext(), &transform, &player, display.IsRunning());
	EntityManager entityManager;

	Level level("./res/levels/lev_1.png");
	level.LoadLevel("./data/level1.dat");

	Camera camera(glm::vec3(0, 0, -2), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);

	Health health(&player);

	transform.SetScale(glm::vec3(3, 3, 0));
	transform2.SetScale(glm::vec3(1.27, 0.95, 0));
	healthTransform.SetScale(glm::vec3(4, 4, 0));
	healthTransform.SetPos(glm::vec3(1.29 - healthTransform.GetScale().x / 5 / 2, 0.98 - healthTransform.GetScale().y / 5 / 4, 0));

	int numFrames = 0;
	double startTime = timeGetTime();

	while (manager.IsRunning())
	{
		numFrames++;

		display.Clear(0.4f, 0.5f, 1.0f, 1.0f);
		shader.Bind();
		shader.Update(transform2, camera);
		level.Bind();
		level.Render();

		shader.Update(transform, camera);
		player.Bind();
		player.Render();


		shader.Update(healthTransform, camera);
		health.Render();

		manager.Update();
		manager.RegisterInput();
		manager.UpdateCollision(WIDTH, HEIGHT, &level);

		double elapsedMS = timeGetTime() - startTime;
		if (elapsedMS)
		{
			double elapsedSeconds = elapsedMS / 1000.0;
			double fps = numFrames / elapsedSeconds;
			//std::cout << fps << std::endl;
		}
		Sleep(1000.0 / 120.0);
	}

	return 0;
}