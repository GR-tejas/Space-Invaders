#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
using namespace sf;

class EventService 
{
private:
	Event game_event;
	RenderWindow* game_window;

	bool isGameWindowOpen();
	bool gameWindowWasClosed();
	bool hasQuitGame();


public:
	EventService();
	~EventService();

	void initialize();
	void update();
	void processEvents();
	bool pressedEscapeKey();
	bool isKeyboardEvent();
	bool pressedLeftKey();
	bool pressedRightKey();
};