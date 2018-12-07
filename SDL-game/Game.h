#pragma once
#ifndef __Game__
#define __Game__

#include <iostream>
#include "Configuration.h"
#include "ObjectInitializer.h"
#include "InputHandler.h"
#include <vector>

class Game
{
public:
	
	~Game() {}
	bool init(const char* title, int xpos, int ypos, 
		int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { m_bRunning = false; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	// a function to access the private running variable
	bool running() { return m_bRunning; }

	//making it singleton
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	Game() {}
	static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Point screen_center;
	SDL_Texture* m_pTexture;
	bool m_bRunning;
	
};


static std::vector< GameObject* > m_gameObjects;
#endif /* defined (__Game__) */