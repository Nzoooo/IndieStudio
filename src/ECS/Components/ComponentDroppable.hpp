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
        ComponentDroppable(bool ableToBePicked = false) : _ableToBePicked(ableToBePicked) {};
        ~ComponentDroppable() = default;

        bool getAbleToBePicked() const;

        void setAbleToBePicked(bool ableToBePicked);

    protected:
    private:
        bool _ableToBePicked;
};