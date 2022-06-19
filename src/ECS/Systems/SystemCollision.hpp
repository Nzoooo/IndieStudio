/*
** EPITECH PROJECT, 2022
** SystemCollision
** File description:
** SystemCollision
*/

#pragma once

#include "ECS/ecs.hpp"
#include "ISystem.hpp"
#include "raylib/include/BoundingBox.hpp"

namespace ecs
{
    class SystemCollision : public ecs::ISystem {
      public:
        static bool checkCollisions(raylib::BoundingBox &box, ecs::IEntity *it, std::vector<ecs::IEntity *> entities);
        static bool checkCollisions(raylib::BoundingBox &box, raylib::BoundingBox &box2);
        static void checkCollisionsBoosts(raylib::BoundingBox &box, ecs::IEntity *it, std::vector<ecs::IEntity *> entities);
        static void checkPosVent(raylib::BoundingBox &box, ecs::IEntity *player, std::vector<ecs::IEntity *> entities);
        static void checkCollisionsBomb(raylib::BoundingBox &box, ecs::IEntity *it, std::vector<ecs::IEntity *> entities);
        static bool checkCollisionsFireBlastBlocks(raylib::BoundingBox &box, std::vector<ecs::IEntity *> entities);
    };
} // namespace ecs
