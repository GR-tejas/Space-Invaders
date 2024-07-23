#include"../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyService.h"
#include"../../Header/Global/ServiceLocator.h"

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

	void EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = new EnemyController();
		enemy_controller->initialize();

		enemy_list.push_back(enemy_controller);
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++) delete(enemy_list[i]);
	}
}