#include "../../Header/Player/PlayerModel.h"

namespace Player
{
	int PlayerModel::player_lives;
	int PlayerModel::enemies_killed;

	PlayerModel::PlayerModel() { entity_type = Entity::EntityType::PLAYER; }

	PlayerModel::~PlayerModel() { }

	void PlayerModel::initialize() { reset(); }

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		currentPosition = initialPostion;

		b_shield = false;
		b_rapid_fire = false;
		b_tripple_laser = false;
	}

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		player_position = initialPostion;

		player_lives = max_player_lives;
		enemies_killed = 0;

		b_shield = false;
		b_rapid_fire = false;
		b_tripple_laser = false;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return currentPosition;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		currentPosition = position;
	}

	bool PlayerModel::isPlayerAlive()
	{
		return playerAlive;
	}

	void PlayerModel::setPlayerAlive(bool alive)
	{
		playerAlive = alive;
	}

	int PlayerModel::getPlayerScore()
	{
		return playerScore;
	}

	void PlayerModel::setPlayerScore(int score)
	{
		playerScore = score;
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}

	Entity::EntityType PlayerModel::getEntityType()
	{
		return entity_type;
	}

	bool PlayerModel::isShieldEnabled()
	{
		return b_shield;
	}

	bool PlayerModel::isRapidFireEnabled()
	{
		return b_rapid_fire;
	}

	bool PlayerModel::isTrippleLaserEnabled()
	{
		return b_tripple_laser;
	}

	void PlayerModel::setShieldState(bool value)
	{
		b_shield = value;
	}

	void PlayerModel::setRapidFireState(bool value)
	{
		b_rapid_fire = value;
	}

	void PlayerModel::setTrippleFireState(bool value)
	{
		b_tripple_laser = value;
	}
}