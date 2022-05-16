/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentMovable
*/

#include "ComponentMovable.hpp"

ComponentMovable::Direction ComponentMovable::getDirection() const
{
    return (_direction);
}

int ComponentMovable::getSpeed() const
{
    return (_speed);
}

bool ComponentMovable::getAbleToMove() const
{
    return this->_ableToMove;
}

void ComponentMovable::setDirection(ComponentMovable::Direction direction)
{
    _direction = direction;
}

void ComponentMovable::setSpeed(int speed)
{
    _speed = speed;
}

void ComponentMovable::setAbleToMove(bool ableToMove) {
    this->_ableToMove = ableToMove;
}