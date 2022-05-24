/*
** EPITECH PROJECT, 2022
** ComponentDroppable.hpp
** File description:
** ComponentDroppable.hpp
*/

#pragma once

#include "IComponent.hpp"

class ComponentDroppable : public ecs::IComponent {
    public:
        ComponentDroppable(bool ableToBeDropped = false) : _ableToBeDropped(ableToBeDropped) {};
        ~ComponentDroppable() = default;

        bool getAbleToBeDropped() const;

        void setAbleToBeDropped(bool ableToBeDropped);

    protected:
    private:
        bool _ableToBeDropped;
};