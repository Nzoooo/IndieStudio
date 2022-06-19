/*
** EPITECH PROJECT, 2022
** SystemIA.hpp
** File description:
** SystemIA.hpp
*/

#pragma once

#include "ECS/ecs.hpp"
#include <chrono>
#include <map>

class SystemIA : public ecs::ISystem {
    public:
        static void update(ecs::Core &core);

    protected:
    private:
        static ecs::IEntity *getBombInRange(ecs::IEntity *_ia, ecs::Core &_core);
        static bool isKillableBlockInRange(ecs::IEntity *_ia, ecs::Core &_core);
        static ComponentMovable::Direction getDirectionOfTheBomb(ecs::IEntity *_ia, ecs::IEntity *bomb);
        static std::vector<ComponentMovable::Direction> getPossibleDirection(ecs::IEntity *_ia, ecs::Core &_core, std::vector<ComponentMovable::Direction> &possibleDirection, ecs::IEntity *bomb = nullptr);

        static void move(ecs::IEntity *_ia, ecs::Core &_core);
        static void move(ecs::IEntity *_ia, ecs::Core &_core, ecs::IEntity *bomb);
        static std::map<std::string, float> getMovement(ecs::IEntity *_ia);
};
