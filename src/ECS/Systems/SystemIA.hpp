/*
** EPITECH PROJECT, 2022
** SystemIA.hpp
** File description:
** SystemIA.hpp
*/

#pragma once

#include "ecs.hpp"
#include <chrono>
#include <map>

class SystemIA : public ecs::ISystem {
    public:
        SystemIA(ecs::Core &core, std::string modelPath, raylib::Vector3 pos, ComponentMovable::Direction dir);
        SystemIA(const SystemIA &other) = delete;
        ~SystemIA();
        SystemIA &operator=(const SystemIA &other) = delete;

        void udpdate();

    protected:
    private:
        ecs::Core &_core;
        ecs::IEntity *_ia;
        std::chrono::time_point<std::chrono::system_clock> _timeInBombRange;

        ecs::IEntity *getBombInRange();
        bool isKillableBlockInRange() const;
        ComponentMovable::Direction getDirectionOfTheBomb(ecs::IEntity *bomb);
        std::vector<ComponentMovable::Direction> getPossibleDirection(ecs::IEntity *bomb = nullptr);

        void move();
        void move(ecs::IEntity *bomb);
        std::map<std::string, float> getMovement();
        bool checkCollisionAt(int posX, int posY) const;
};
