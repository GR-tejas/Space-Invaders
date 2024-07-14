#include "../../Header/Event/EventService.h"//event
#include "../../Header/Main/GameServices.h"
#include "../../Header/Graphic/GraphicsServices.h"

namespace EventSpace
{
	using namespace Global;
	EventService::EventService()
	{
		game_window = nullptr;
	}

	EventService::~EventService() = default;

	void EventService::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
	}

	void EventService::update()
	{

	}

	void EventService::processEvents()
	{
		if (isGameWindowOpen())
		{
			while (game_window->pollEvent(game_event))
			{
				if (gameWindowWasClosed() || hasQuitGame())
				{
					game_window->close();
				}
			}
		}
	}

	bool EventService::hasQuitGame()
	{
		return (isKeyboardEvent() && pressedEscapeKey());
	}

	bool EventService::isKeyboardEvent()
	{
		return game_event.type == sf::Event::KeyPressed;
	}

	bool EventService::pressedEscapeKey()
	{
		return game_event.key.code == sf::Keyboard::Escape;
	}

	bool EventService::pressedLeftKey()
	{
		return(Keyboard::isKeyPressed(Keyboard::Left));
	}

	bool EventService::pressedRightKey()
	{
		return(Keyboard::isKeyPressed(Keyboard::Right));
	}

	bool EventService::isGameWindowOpen()
	{
		return game_window != nullptr;
	}

	bool EventService::gameWindowWasClosed()
	{
		return game_event.type == sf::Event::Closed;
	}
}