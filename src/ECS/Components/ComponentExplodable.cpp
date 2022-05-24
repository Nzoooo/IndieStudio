/*
** EPITECH PROJECT, 2022
** ComponentExplodable.cpp
** File description:
** ComponentExplodable.cpp
*/

#include "ComponentExplodable.hpp"

std::size_t ComponentExplodable::getDeflagrationRange() const
{
    return (_deflagrationRange);
}

bool ComponentExplodable::getAbleToExplode() const
{
    return (_ableToExplode);
}

void ComponentExplodable::setDeflagrationRange(std::size_t deflagrationRange)
{
    _deflagrationRange = deflagrationRange;
}

void ComponentExplodable::setAbleToExplode(bool ableToExplode)
{
    _ableToExplode = ableToExplode;
}