#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	std::cout << "init success\n";
	m_bRunning = true; //everything inited successfully, start main loop

	/*
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/hero.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	SDL_QueryTexture(m_pTexture, NULL, NULL, 
		&m_sourceRectangle.w, &m_sourceRectangle.h);
	*/

	SDL_Surface* pTempSurface = IMG_Load("assets/flash.png");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	m_sourceRectangle.w = 100;
	m_sourceRectangle.h = 100;
	SDL_Point screen_center = {
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED
	};

	//m_destinationRectangle.x = m_sourceRectangle.x = 0;
	//m_destinationRectangle.y = m_sourceRectangle.y = 0;
	//m_sourceRectangle.x = 50;
	//m_sourceRectangle.y = 50;
	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;

	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	return true;
}

void Game::render()
{
	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;
	SDL_RenderClear(m_pRenderer); //clear the renderer to the draw color
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle,
		int((SDL_GetTicks() / 10) % 360), 0, SDL_FLIP_HORIZONTAL); 
	
	m_destinationRectangle.x = 200;
	m_destinationRectangle.y = 250;
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle,
		int((SDL_GetTicks() / 20) % 360), 0, SDL_FLIP_NONE);
	
	m_destinationRectangle.x = 400;
	m_destinationRectangle.y = 350;
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle,
		int((SDL_GetTicks() / 5) % 360), 0, SDL_FLIP_VERTICAL);
	
	m_destinationRectangle.x = 350;
	m_destinationRectangle.y = 180; 
	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle,
		int((SDL_GetTicks() / 40) % 360), &screen_center , SDL_FLIP_NONE);

	SDL_RenderPresent(m_pRenderer); //draw to the screen
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
		break;

		default:
		break;
		}
	}
}

void Game::update() 
{
	m_sourceRectangle.x = 100 * int(((SDL_GetTicks() / 100) % 5));
}