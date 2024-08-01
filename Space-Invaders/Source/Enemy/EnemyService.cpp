#include "../../header/Enemy/EnemyService.h"
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Time/TimeService.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../header/Enemy/Controllers/ZapperController.h"
//#include "../../header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../header/Enemy/Controllers/SubzeroController.h"
#include "../../header/Enemy/Controllers/UFOController.h"
#include "../../header/Collision/ICollider.h"

namespace Enemy
{
	using namespace Global;
	using namespace TimeSpace;
	using namespace Controller;
	using namespace Collision;

	EnemyService::EnemyService() { std::srand(static_cast<unsigned>(std::time(nullptr))); }
	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::initialize()
	{
		spawn_time = spawn_intreval;
	}

	void EnemyService::update()
	{
		updateSpawnTime();
		processEnemySpawn();

		for (EnemyController* enemy : enemy_list)
			enemy->update();

		destroyFlaggedEnemies();
	}

	void EnemyService::render()
	{
		for (EnemyController* enemy : enemy_list)
			enemy->render();
	}

	void EnemyService::updateSpawnTime()
	{
		spawn_time += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_time >= spawn_intreval)
		{
			spawnEnemy();
			spawn_time = 0.0f;
		}
	}
	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new Enemy::Controller::ZapperController(Enemy::EnemyType::ZAPPER);

			/*case::Enemy::EnemyType::THUNDER_SNAKE:
				return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);*/

		case::Enemy::EnemyType::SUBZERO:
			return new Enemy::Controller::SubzeroController(Enemy::EnemyType::SUBZERO);

			case::Enemy::EnemyType::UFO:
				return new Enemy::Controller::UFOController(Enemy::EnemyType::UFO);
		}
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		enemy_controller->initialize();

		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int random_value = std::rand() % (static_cast<int>(Enemy::EnemyType::UFO) + 1);
		return static_cast<Enemy::EnemyType>(random_value);
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		dynamic_cast<ICollider*>(enemy_controller)->disableCollision();
		flagged_enemy_list.push_back(enemy_controller);
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
	}

	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0; i < flagged_enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_enemy_list[i]));
			delete (flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		dynamic_cast<ICollider*>(enemy_controller)->disableCollision();
		flagged_enemy_list.push_back(enemy_controller);
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(enemy_list[i]));
			delete (enemy_list[i]);
		}
		enemy_list.clear();
	}

	void EnemyService::reset()
	{
		destroy();
		spawn_timer = 0.0f;
	}