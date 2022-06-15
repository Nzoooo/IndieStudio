/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentMovable
*/

#include "ComponentMovable.hpp"

float ComponentMovable::getSpeed() const
{
    return (_speed);
}

void ComponentMovable::setSpeed(int speed)
{
    _speed = speed;
}
