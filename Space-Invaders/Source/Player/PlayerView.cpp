#include "../../header/Player/PlayerView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Graphic/GraphicsServices.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView() { createUIElements(); }

	PlayerView::~PlayerView() { destroy(); }

	void PlayerView::initialize(PlayerController* controller)
	{

		player_controller = controller;
		initializeImage();
	}

	void PlayerView::createUIElements()
	{
		player_image = new ImageView();
	}

	void PlayerView::initializeImage()
	{
		player_image->initialize(Config::player_texture_path, player_sprite_width, player_sprite_height, player_controller->getPlayerPosition());
	}	

	void PlayerView::update()
	{
		player_image->setPosition(player_controller->getPlayerPosition());
		player_image->update();

	}

	void PlayerView::render()
	{
		player_image->render();
	}

	void PlayerView::destroy()
	{
		delete(player_image);
	}

	const sf::Sprite& PlayerView::getPlayerSprite()
	{
		return player_image->getSprite();
	}
		
}
