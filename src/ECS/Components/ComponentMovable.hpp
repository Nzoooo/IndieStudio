/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** ComponentMovable
*/

#ifndef COMPONENTMOVABLE_HPP_
#define COMPONENTMOVABLE_HPP_

#include "IComponent.hpp"

class ComponentMovable : public ecs::IComponent {
    public:
        enum Direction {LEFT, RIGHT, UP, DOWN};

        ComponentMovable(Direction direction, int speed = 0, bool ableToMove = true) : _direction(direction), _speed(speed), _ableToMove(ableToMove) {};
        ~ComponentMovable() = default;

        Direction getDirection() const;
        int getSpeed() const;
        bool getAbleToMove() const;

        void setDirection(Direction direction);
        void setSpeed(int speed);
        void setAbleToMove(bool);

    private:
        Direction _direction;
        int _speed;
        bool _ableToMove;
};

#endif /* !COMPONENTMOVABLE_HPP_ */