#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

PlayerService::PlayerService()
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerService::update()
{
	processPlayerInput();
	playerSprite.setPosition(getPosition());
}

void PlayerService::render()
{
	game_window->draw(playerSprite);
}

void PlayerService::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();

	if (event_service->isKeyboardEvent())
	{
		if (event_service->pressedLeftKey())
		{
			moveLeft();
		}
		if (event_service->pressedRightKey())
		{
			moveRight();
		}
	}
}

void PlayerService::initializePlayerSprite()
{
	if (playerTexture.loadFromFile(player_texture_path))
	{
		playerSprite.setTexture(playerTexture);
	}
}

void PlayerService::moveLeft() 
{
	position.x -= moveSpeed  * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerService::moveRight()
{
	position.x += moveSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

Vector2f PlayerService::getPosition() 
{
	return position;
}
int PlayerService::getMoveSpeed()
{
	return moveSpeed;
}