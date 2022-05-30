/*
** EPITECH PROJECT, 2022
** ComponentPickable.hpp
** File description:
** ComponentPickable.hpp
*/

#pragma once

#include "IComponent.hpp"

class ComponentPickable : ecs::IComponent {
    public:
        ComponentPickable(bool ableToBePicked = false) : _ableToBePicked(ableToBePicked) {};
        ~ComponentPickable() = default;

        bool getAbleToBePicked() const;

        void setAbleToBePicked(bool ableToBePicked);

    protected:
    private:
        bool _ableToBePicked;
};