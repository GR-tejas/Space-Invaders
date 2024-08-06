#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	using namespace Bullet;

	namespace Controller
	{
		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(EnemyType::THUNDER_SNAKE) { std::cout << "10"; }

		ThunderSnakeController::~ThunderSnakeController() { }

		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
			rate_of_fire = zapper_rate_of_fire;
		}

		void ThunderSnakeController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset,
				Bullet::MovementDirection::DOWN);
		}

		void ThunderSnakeController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;

			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void ThunderSnakeController::moveLeft()
		{

			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			currentPosition.x -= enemy_model->enemyMoveSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void ThunderSnakeController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			currentPosition.x += enemy_model->enemyMoveSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}

		void ThunderSnakeController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			currentPosition.y += enemy_model->enemyMoveSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
			{
				if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x)
				{
					enemy_model->setMovementDirection(MovementDirection::RIGHT);
				}
				else
				{
					enemy_model->setMovementDirection(MovementDirection::LEFT);
				}
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}
	}
}