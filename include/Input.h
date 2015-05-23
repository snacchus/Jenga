#pragma once

#include <windows.h>
#include <unordered_map>

enum MouseButton {
	MBUTTON1 = RI_MOUSE_BUTTON_1_DOWN | RI_MOUSE_BUTTON_1_UP,
	MBUTTON2 = RI_MOUSE_BUTTON_2_DOWN | RI_MOUSE_BUTTON_2_UP,
	MBUTTON3 = RI_MOUSE_BUTTON_3_DOWN | RI_MOUSE_BUTTON_3_UP,
	MBUTTON4 = RI_MOUSE_BUTTON_4_DOWN | RI_MOUSE_BUTTON_4_UP,
	MBUTTON5 = RI_MOUSE_BUTTON_5_DOWN | RI_MOUSE_BUTTON_5_UP,
	MBUTTONLEFT = MBUTTON1,
	MBUTTONRIGHT = MBUTTON2,
	MBUTTONMIDDLE = MBUTTON3
};

struct Button
{
	bool down, pressed, released;
	Button() : down(false), pressed(false), released(false) { }
};

class Input
{
private:
	std::unordered_map<USHORT, Button> m_keyboardState;
	std::unordered_map<MouseButton, Button> m_mouseButtons;
	int m_mx, m_my, m_mxDelta, m_myDelta;

	HWND m_hWnd;

	void handle(RAWINPUT * raw);
	void preUpdate();
	void update();

	void updateButton(Button& b, bool down);
	void retrieveCursorPos();

	friend class Engine;

public:
	Input(HWND hWnd);

	bool getKeyDown(USHORT key);
	bool getKeyPressed(USHORT key);
	bool getKeyReleased(USHORT key);

	bool getMouseButtonDown(MouseButton button);
	bool getMouseButtonPressed(MouseButton button);
	bool getMouseButtonReleased(MouseButton button);

	int getMouseX() const;
	int getMouseY() const;
	int getMouseDeltaX() const;
	int getMouseDeltaY() const;
};

extern Input * input;
