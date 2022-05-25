/*
** EPITECH PROJECT, 2022
** ComponentClickable.cpp
** File description:
** ComponentClickable.cpp
*/

#include "ComponentClickable.hpp"

bool ComponentClickable::getAbleToBeClicked() const
{
    return (_ableToBeClicked);
}

void ComponentClickable::setAbleToBeClicked(bool ableToBeClicked)
{
    _ableToBeClicked = ableToBeClicked;
}