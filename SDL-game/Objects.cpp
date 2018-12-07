#include "Objects.h"

//-------------------PLAYER------------------//

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams) {}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	SDLGameObject::update();
	//m_currentFrame = (m_currentFrame + 1) % 5;
}

void Player::clean()
{
}

void Player::handleInput()
{
	//Replace 2 with an actual joystick so it will be working perfectly

	
	if (TheInputHandler::Instance()->joysticksInitialised())
	{
		//Left stick x direction
		if (TheInputHandler::Instance()->xvalue(2, 1) > 0
			|| TheInputHandler::Instance()->xvalue(2, 1) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(2, 1));
		}

		//Left stick y direction
		if (TheInputHandler::Instance()->yvalue(2, 1) > 0
			|| TheInputHandler::Instance()->yvalue(2, 1) < 0)
		{
			m_velocity.setY((1 * TheInputHandler::Instance()->yvalue(2, 1)));
		}

		//Right stick x direction
		if (TheInputHandler::Instance()->xvalue(2, 2) > 0
			|| TheInputHandler::Instance()->xvalue(2, 2) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(2, 2));
		}

		//Right stick y direction
		if (TheInputHandler::Instance()->yvalue(2, 2) > 0
			|| TheInputHandler::Instance()->yvalue(2, 2) < 0)
		{
			m_velocity.setY((1 * TheInputHandler::Instance()->yvalue(2, 2)));
		}

	}
}

//--------------------ENEMY------------------//

Enemy::Enemy(const LoaderParams* pParams) :
	SDLGameObject(pParams) {}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);
}

void Enemy::clean()
{
}


