#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicsServices.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;

	EnemyView::EnemyView() { }

	EnemyView::~EnemyView() { }

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicsService()->getGameWindow();
		initializeEnemySprite(enemy_controller->getEnemyType());
	}

	void EnemyView::initializeEnemySprite(EnemyType type)
	{
		switch (type)
		{
		case::Enemy::EnemyType::SUBZERO:
			if (Enemy_texture.loadFromFile(subzero_texture_path))
			{
				Enemy_sprite.setTexture(Enemy_texture);
				scaleEnemySprite();
			}
			break;
		case::Enemy::EnemyType::ZAPPER:
			if (Enemy_texture.loadFromFile(zapper_texture_path))
			{
				Enemy_sprite.setTexture(Enemy_texture);
				scaleEnemySprite();
			}
			break;
		}
	}

	void EnemyView::scaleEnemySprite()
	{
		Enemy_sprite.setScale(
			static_cast<float>(Enemy_sprite_width) / Enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(Enemy_sprite_height) / Enemy_sprite.getTexture()->getSize().y
		);
	}

	void EnemyView::update()
	{
		Enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		game_window->draw(Enemy_sprite);
	}
}