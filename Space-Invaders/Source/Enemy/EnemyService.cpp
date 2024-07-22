#include"../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyService.h"
#include"../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyService::EnemyService() { enemy = nullptr; }
	EnemyService::~EnemyService() { Destroy(); }

	void EnemyService::initialize()
	{
		spawnEnemy();
	}

	void EnemyService::update()
	{

	}

	void EnemyService::render()
	{
		enemy->render();
	}

	void EnemyService::spawnEnemy()
	{
		enemy = new EnemyController();
		enemy->initialize();
	}

	void EnemyService::Destroy()
	{
		delete(enemy);
	}
}