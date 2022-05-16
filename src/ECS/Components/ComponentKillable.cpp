/*
** EPITECH PROJECT, 2022
** ComponentKillable.cpp$
** File description:
** ComponentKillable.cpp
*/

#include "ComponentKillable.hpp"

bool ComponentKillable::getAbleToBeKilled() const
{
    return (_ableToBeKilled);
}

void ComponentKillable::setAbleToBeKilled(bool ableToBeKilled)
{
    _ableToBeKilled = ableToBeKilled;
}