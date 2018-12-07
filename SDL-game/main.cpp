#include "Game.h"

int main(int argc, char* args[])
{
	Uint32 frameStart, frameTime;

	std::cout << "game init attempt...\n";
	if (Game::Instance()->init("Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, false))
	{
		while (Game::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}

		}

		Game::Instance()->clean();
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	

	return 0;
}
