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

	if (event_service->pressedLeftKey())
	{
		move(-1.0f * getMoveSpeed());
	}
	if (event_service->pressedRightKey())
	{
		move(1.0f * getMoveSpeed());
	}
}

void PlayerService::initializePlayerSprite()
{
	if (playerTexture.loadFromFile(player_texture_path))
	{
		playerSprite.setTexture(playerTexture);
	}
}

void PlayerService::move(float offsetX) 
{
	position.x += offsetX;
}

Vector2f PlayerService::getPosition() 
{
	return position;
}
int PlayerService::getMoveSpeed()
{
	return moveSpeed;
}