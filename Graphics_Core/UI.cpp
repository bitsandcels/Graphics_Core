//#include "UI.h"
//
//UI::UI()
//{
//	m_MousedOver = 0;
//	m_Activated = 0;
//}
//
//UI::UI(int id, D3D11VECTOR3 position, POINT size) :
//	m_ID(id), m_Position(position), m_Size(size)
//{
//	m_MousedOver = false;
//	m_Activated = false;
//	m_MousePressed = false;
//}
//
//void UI::Activate(bool active)
//{
//	m_Activated = active;
//	if (active == false)
//	{
//		m_MousedOver = false;
//		m_MousePressed = false;
//	}
//}
//
//int UI::MouseOverCheck(POINT mousePos)
//{
//	if (!m_Activated)
//		return 0;
//	if (mousePos.x < m_Position.x || mousePos.y < m_Position.y ||
//		mousePos.x > m_Position.x + m_Size.x || mousePos.y > m_Position.y + m_Size.y)
//	{
//		return MouseOut();
//	}
//	return MouseOver();
//}