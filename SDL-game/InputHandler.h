#pragma once
#ifndef __InputHandler__
#define __InputHandler__

#include <SDL.h>
#include <vector>
#include "Vector2D.h"

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();
	void initialiseJoysticks();
	bool joysticksInitialised() { return m_bJoysticksInitialised; }
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

private:
	InputHandler() {}
	~InputHandler() {}
	
	const int m_joystickDeadZone = 10000;
	std::vector< std::pair< Vector2D*, Vector2D*> > m_joystickValues;
	std::vector< SDL_Joystick* > m_joysticks;
	
	bool m_bJoysticksInitialised;

	static InputHandler* s_pInstance;
};
typedef InputHandler TheInputHandler;

#endif // !__InputHandler__
