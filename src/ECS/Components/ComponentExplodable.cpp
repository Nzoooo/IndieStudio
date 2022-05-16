/*
** EPITECH PROJECT, 2022
** ComponentExplodable.cpp
** File description:
** ComponentExplodable.cpp
*/

#include "ComponentExplodable.hpp"

bool ComponentExplodable::ableToExplode() const
{
    return (_ableToExplode);
}

void ComponentExplodable::setAbleToExplode(bool ableToExplode)
{
    _ableToExplode = ableToExplode;
}