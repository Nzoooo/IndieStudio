/*
** EPITECH PROJECT, 2022
** ComponentCollider.hpp
** File description:
** ComponentCollider.hpp
*/

#pragma once

#include "IComponent.hpp"

class ComponentCollider : public ecs::IComponent {
    public:
        ComponentCollider(bool ableToTakeCollider = true) : _ableToTakeCollider(ableToTakeCollider) {};
        ~ComponentCollider() = default;

        bool getAbleToTakeCollider() const;

        void setAbleToTakeCollider(bool ableToTakeCollider);

    private:
        bool _ableToTakeCollider;
};