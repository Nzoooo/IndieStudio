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
        SystemIA();
        SystemIA(const SystemIA &other) = delete;
        ~SystemIA();
        SystemIA &operator=(const SystemIA &other) = delete;


    protected:
    private:
        ecs::IEntity *_ia;

        ecs::IComponent *getBombInRange(ecs::IComponent *bomb);
        bool isKillableBlockInRange();
        void setDirectionWithBomb(ecs::IComponent *bomb);
};
