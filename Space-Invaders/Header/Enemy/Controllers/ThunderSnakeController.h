#pragma once
#include "../../header/Enemy/EnemyController.h"
#include"../../Header/Bullet/BulletConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            float vertical_travel_distance = 100.f;
            float zapper_rate_of_fire = 150.f;


        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void fireBullet();
            void initialize() override;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();
        };
    }
}