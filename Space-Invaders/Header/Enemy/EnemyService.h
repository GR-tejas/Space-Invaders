#pragma once

namespace Enemy
{
	class EnemyService
	{
	private:

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();
	};
}