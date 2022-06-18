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
        static bool checkCollisions(raylib::BoundingBox &box, std::vector<ecs::IEntity *> entities);
    };
} // namespace ecs
