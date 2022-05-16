/*
** EPITECH PROJECT, 2022
** ComponentExplodable.hpp
** File description:
** ComponentExplodable.hpp
*/

#pragma once

#include "IComponent.hpp"

class ComponentExplodable : public ecs::IComponent {
    public:
        ComponentExplodable(bool ableToExplode = false) : _ableToExplode(ableToExplode) {};
        ~ComponentExplodable() = default;

        bool ableToExplode() const;

        void setAbleToExplode(bool ableToExplode);

    protected:
    private:
        bool _ableToExplode;
};