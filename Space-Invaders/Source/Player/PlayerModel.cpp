#include "../../Header/Player/PlayerModel.h"

PlayerModel::PlayerModel() { }

PlayerModel::~PlayerModel() { }

void PlayerModel::initialize() { reset(); }

void PlayerModel::reset()
{
	playerAlive = true;
	currentPosition = initialPostion;
	playerScore = 0;
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