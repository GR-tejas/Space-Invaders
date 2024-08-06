#include"../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyService.h"
#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include"../../Header/Enemy/Controllers/SubZeroController.h"
#include"../../Header/Enemy/Controllers/ZapperController.h"
#include"../../Header/Enemy/Controllers/UFOController.h"
#include<iostream>

namespace Enemy
{
	using namespace Global;
	using namespace TimeSpace;

	EnemyService::EnemyService() {  }
	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::initialize()
	{
		spawn_time = spawn_intreval;
	}

	void EnemyService::update()
	{
		updateSpawnTime();
		processEnemySpawn();

		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->update();
	}

	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->render();
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
		int randomType = std::rand() % 3;
		std::cout << randomType<<"\n";
		return static_cast<EnemyType>(randomType);
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		delete (enemy_controller);
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++) delete(enemy_list[i]);
	}
}