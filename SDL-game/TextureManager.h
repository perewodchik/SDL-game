#ifndef __TextureManager__
#define __TextureManager__

#include <map>
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
	bool load(std::string fileName, std::string id, SDL_Renderer * pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	std::map<std::string, SDL_Texture* > m_textureMap;
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	
private:
	TextureManager() {};
	static TextureManager* s_pInstance;
};

#endif
