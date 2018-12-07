#pragma once
#ifndef __Objects__
#define __Objects__

#include "ObjectInitializer.h"
#include "InputHandler.h"
#include "SDLGameObject.h"

class Player : public SDLGameObject // inherit from GameObject
{
public:
	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
};

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
};

#endif // !__Objects__



