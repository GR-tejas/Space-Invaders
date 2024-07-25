#pragma once
#include<vector>

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:
		const float spawn_intreval = 3.0f;

		std::vector<EnemyController*> enemy_list;
		float spawn_time = 0.0f;

		void updateSpawnTime();
		void processEnemySpawn();
		void destroy();
		
	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		void spawnEnemy();

	};
}