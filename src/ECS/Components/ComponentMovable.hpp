/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentMovable
*/

#ifndef COMPONENTMOVABLE_HPP_
#define COMPONENTMOVABLE_HPP_

#include "IComponent.hpp"

class ComponentMovable : public ecs::IComponent {
    public:
        enum Direction {LEFT, RIGHT, UP, DOWN};

        ComponentMovable(Direction direction = Direction::LEFT, int speed = 0, bool ableToMove = true) : _direction(direction), _speed(speed), _ableToMove(ableToMove) {};
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