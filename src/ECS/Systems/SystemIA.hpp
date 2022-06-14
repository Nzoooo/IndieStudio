/*
** EPITECH PROJECT, 2022
** SystemIA.hpp
** File description:
** SystemIA.hpp
*/

#pragma once

#include "ecs.hpp"

class SystemIA : public ecs::ISystem {
    public:
        SystemIA(ecs::Core &core, int posX, int posY);
        SystemIA(const SystemIA &other) = delete;
        ~SystemIA();
        SystemIA &operator=(const SystemIA &other) = delete;

        void udpdate();

    protected:
    private:
        ecs::Core *_core;
        ecs::IEntity *_ia;
        int _blastRange;

        ecs::IComponent *getBombInRange(std::vector<ecs::IEntity *> &entities);
        bool isKillableBlockInRange();
        void setDirectionWithBomb(ecs::IEntity *bomb);

        void move();
        bool checkCollisionAt(int posX, int posY);
};
