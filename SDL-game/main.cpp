#include "Game.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

Game* g_game = 0;

int main(int argc, char* args[])
{
	g_game = new Game();

	g_game->init("Game!!!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}

	g_game->clean();

	return 0;
}