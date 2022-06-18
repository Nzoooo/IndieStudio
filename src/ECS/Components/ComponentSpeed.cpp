/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentSpeed
*/

#include "ComponentSpeed.hpp"

std::size_t ComponentSpeed::getSpeed() const
{
    return (_speed);
}

void ComponentSpeed::setSpeed(std::size_t speed)
{
    _speed = speed;
}
