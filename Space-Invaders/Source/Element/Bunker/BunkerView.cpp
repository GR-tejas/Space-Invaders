#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Element/Bunker/BunkerController.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;

		BunkerView::BunkerView() { }

		BunkerView::~BunkerView() { }

		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
			initializeImage();
		}

		void BunkerView::initializeImage()
		{
			if (bunker_texture.loadFromFile(bunker_texture_path))
			{
				bunker_sprite.setTexture(bunker_texture);
				scaleSprite();
			}
		}


		void BunkerView::scaleSprite()
		{
			bunker_sprite.setScale(
				static_cast<float>(bunker_sprite_width) / bunker_sprite.getTexture()->getSize().x,
				static_cast<float>(bunker_sprite_height) / bunker_sprite.getTexture()->getSize().y
			);
		}


		void BunkerView::update()
		{
			bunker_sprite.setPosition(bunker_controller->getBunkerPosition());
		}

		void BunkerView::render()
		{
			game_window->draw(bunker_sprite);
		}

	}
}