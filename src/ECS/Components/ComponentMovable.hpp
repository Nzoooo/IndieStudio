/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** ComponentMovable
*/

#ifndef COMPONENTMOVABLE_HPP_
#define COMPONENTMOVABLE_HPP_

#include "IComponent.hpp"

class componentMovable : public ecs::IComponent {
    public:
        componentMovable(bool ableToMove = true):_ableToMove(ableToMove) {};
        ~componentMovable() = default;

        bool getAbleToMove() const;
        void setAbleToMove(bool);

    private:
        bool _ableToMove;
};

#endif /* !COMPONENTMOVABLE_HPP_ */