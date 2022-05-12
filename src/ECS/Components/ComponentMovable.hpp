/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** ComponentMovable
*/

#ifndef COMPONENTMOVABLE_HPP_
#define COMPONENTMOVABLE_HPP_

#include "IComponent.hpp"

class ComponentMovable : ecs::IComponent {
    public:
        ComponentMovable(bool ableToMove = true):_ableToMove(ableToMove) {};
        ~ComponentMovable() = default;

        bool getAbleToMove() const;
        void setAbleToMove(bool);

    private:
        bool _ableToMove;
};

#endif /* !COMPONENTMOVABLE_HPP_ */