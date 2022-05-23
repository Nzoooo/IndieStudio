/*
** EPITECH PROJECT, 2022
** ComponentDroppable.cpp
** File description:
** ComponentDroppable.cpp
*/

#include "ComponentDroppable.hpp"

bool ComponentDroppable::getAbleToBeDropped() const
{
    return (_ableToBeDropped);
}

void ComponentDroppable::setAbleToBeDropped(bool ableToBeDropped)
{
    _ableToBeDropped = ableToBeDropped;
}