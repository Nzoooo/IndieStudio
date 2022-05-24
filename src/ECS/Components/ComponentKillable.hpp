/*
** EPITECH PROJECT, 2022
** ComponentKillable.hpp
** File description:
** ComponentKillable.hpp
*/

#pragma once

#include "IComponent.hpp"

class ComponentKillable : public ecs::IComponent {
    public:
        ComponentKillable(bool ableToBeKilled = false) : _ableToBeKilled(ableToBeKilled) {};
        ~ComponentKillable() = default;

        bool getAbleToBeKilled() const;

        void setAbleToBeKilled(bool ableToBeKilled);

    protected:
    private:
        bool _ableToBeKilled;
};