#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

namespace Enemy
{
	enum class EnemyType;
	enum class EnemyState;
	enum class MovementDirection;

	class EnemyModel
	{
	public:
		EnemyModel(EnemyType type);
		~EnemyModel();

		sf::Vector2f reference_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f enemy_position;

		MovementDirection movement_direction;
		EnemyType enemy_type;
		EnemyState enemy_state;

		const sf::Vector2f left_most_position = sf::Vector2f(50.0f, 950.0f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.0f, 950.0f);
				
		const float vertical_travel_distance = 100.f;
		const float enemyMoveSpeed = 50.0f;

		void initialize();

		Vector2f getEnemyPosition();
		void setEnemyPosition(Vector2f position);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		/*bool isEnemyAlive();
		void setEnemyAlive(bool alive);

		int getEnemyScore();
		void setEnemyScore(int score);*/


		EnemyType getEnemyType();
		void setEnemyType(EnemyType type);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);

	private:
		const Vector2f initialPostion = Vector2f(500.0f, 500.0f);
		Vector2f currentPosition;
		bool enemyAlive;

		MovementDirection movement_direction;
	};
}