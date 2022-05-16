/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
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