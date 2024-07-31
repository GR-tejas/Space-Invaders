#pragma once
#include<SFML/Graphics.hpp>
#include "../../header/Entity/EntityConfig.h"

using namespace sf;

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		FROZEN,
		DEAD,
	};

	class PlayerModel
	{
	private:
		const Vector2f initialPostion = Vector2f(915.0f, 950.0f);
		Vector2f currentPosition;
		bool playerAlive;
		PlayerState player_state;
		Entity::EntityType entity_type;

		bool b_shield;
		bool b_rapid_fire;
		bool b_tripple_laser;
			
	public:
		PlayerModel();
		~PlayerModel();

		const sf::Vector2f left_most_position = sf::Vector2f(50.0f, 950.0f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.0f, 950.0f);

		const Vector2f barrel_position_offset = Vector2f(0.f, 20.f);
		const Vector2f second_weapon_position_offset = Vector2f(45.f, 0.f);
		const sf::Vector2f third_weapon_position_offset = sf::Vector2f(-45.f, 0.f);

		const float shiled_powerup_duration = 10.f;
		const float rapid_fire_powerup_duration = 10.f;
		const float tripple_laser_powerup_duration = 10.f;

		const float shiled_powerup_duration = 10.f;
		const float rapid_fire_powerup_duration = 10.f;
		const float tripple_laser_powerup_duration = 10.f;

		const float freeze_duration = 2.f;

		const float fire_cooldown_duration = 0.2f;
		const float rapid_fire_cooldown_duration = 0.05f;
		const float tripple_laser_position_offset = 30.f;

		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freeze_duration;

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

		Entity::EntityType getEntityType();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

		bool isShieldEnabled();
		bool isRapidFireEnabled();
		bool isTrippleLaserEnabled();

		void setShieldState(bool value);
		void setRapidFireState(bool value);
		void setTrippleFireState(bool value);
	};
}