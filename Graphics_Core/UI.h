//#pragma once
//
//#include "AssetHouse.h"
//
//struct SUIInfo
//{
//	int ID;
//	D3D11VECTOR3 Position;
//	POINT Size;
//	SUIInfo() :
//		ID(0), Position(0, 0, 0), Size(0) {}
//};
//
//class UI
//{
//public:
//	inline bool IsActivated() { return m_Activated; }
//	virtual void Activate(bool active);
//	virtual int GetID() { return m_ID; }
//	virtual void Update(float dt) = 0;
//	virtual int MouseOverCheck(POINT mousePos);
//	virtual int Click() { return 0; }
//	virtual int MouseButtonDown(int button) { return 0; }
//	virtual int MouseButtonUp(int button) { return 0; }
//	virtual virtual void SetPosition(D3D11VECTOR3 pos) { m_Position = pos; }
//	void SetSize(POINT size) { m_Size = size; }
//	D3D11VECTOR3 GetPosition() { return m_Position; }
//	POINT GetSize() { return m_Size; }
//	UI() {};
//	UI(int id, D3D11VECTOR3 position, POINT size) {};
//	virtual ~UI() {};
//protected:
//	virtual int MouseOver() = 0;
//	virtual int MouseOut() = 0;
//
//	D3D11VECTOR3 m_Position;
//	POINT m_Size;
//	bool m_MousedOver;
//	bool m_MousePressed;
//	bool m_Activated;
//	int m_ID;
//};