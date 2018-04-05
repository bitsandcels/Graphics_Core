#include "Button.h"

Button::Button(SUIInfo info) 
{
	UI(info.ID, info.Position, info.Size);
}

Button::~Button()
{
}



int Button::Click()
{
	if (!m_Activated || !m_MousedOver)
		return 0;
	return m_ID;
}

int Button::MouseButtonDown(int button)
{
	if (!m_Activated || !m_MousedOver)
		return 0;
	switch (button)
	{
	case 0:
	{
		m_MousePressed = true;
		return m_ID;
		break;
	}
	}
	return 0;
}

int Button::MouseButtonUp(int button)
{
	if (!m_Activated)
		return 0;
	if (m_MousedOver && m_MousePressed)
	{
		m_MousePressed = false;
		return m_ID;
	}
	m_MousePressed = false;
	return 0;
}

int Button::MouseOver()
{
	if (m_Activated)
		m_MousedOver = true;
	return 0;
}

int Button::MouseOut()
{
	if (m_Activated)
		m_MousedOver = false;
	return 0;
}
