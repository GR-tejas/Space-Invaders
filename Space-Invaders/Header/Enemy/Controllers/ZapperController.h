#pragma once
#include "../../header/Enemy/EnemyController.h"
#include"../../Header/Bullet/BulletConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
        private:
            float vertical_travel_distance = 100.f;
            float zapper_rate_of_fire = 150.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();
        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void fireBullet();
            void initialize() override;
        };
    }
}