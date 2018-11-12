#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

class Game
{
public:
	Game() {}
	~Game() {}

	//simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, 
		int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	// a function to access the private running variable
	bool running() { return m_bRunning; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Point screen_center;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	bool m_bRunning;
};



#endif /* defined (__Game__) */