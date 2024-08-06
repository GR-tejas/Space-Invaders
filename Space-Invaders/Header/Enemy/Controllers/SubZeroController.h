#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float vertical_movement_speed = 100.f;
            float subzero_rate_of_fire = 150.f;

            
        public:
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void move() override;
            void moveDown();
            void fireBullet();
            void initialize() override;
        };
    }
}