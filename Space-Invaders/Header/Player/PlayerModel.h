#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD,
	};

	class PlayerModel
	{
	public:
		PlayerModel();
		~PlayerModel();

		const sf::Vector2f left_most_position = sf::Vector2f(50.0f, 950.0f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.0f, 950.0f);

		const float playerMoveSpeed = 550.0f;

		void initialize();

		void reset();

		Vector2f getPlayerPosition();

		void setPlayerPosition(Vector2f position);

		int playerScore;

		bool isPlayerAlive();
		void setPlayerAlive(bool alive);

		int getPlayerScore();
		void setPlayerScore(int score);


		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

	private:
		const Vector2f initialPostion = Vector2f(915.0f, 950.0f);
		Vector2f currentPosition;
		bool playerAlive;
		PlayerState player_state;
	};
}