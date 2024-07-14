#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"


PlayerView::PlayerView() { }

PlayerView::~PlayerView() { }

void PlayerView::initialize()
{

	game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerView::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
		scalePlayerSprite();
	}
}

void PlayerView::scalePlayerSprite()
{
	player_sprite.setScale(
		static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
		static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y
	);
}

void PlayerView::update()
{
	player_sprite.setPosition(player_controller->getPlayerPosition());
}

void PlayerView::render()
{
	game_window->draw(player_sprite);
}

void PlayerView::initialize(PlayerController* controller)
{
	player_controller = controller; //to later use it for setting position
	game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
	initializePlayerSprite();
}

