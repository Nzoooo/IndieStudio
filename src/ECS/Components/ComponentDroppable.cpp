/*
** EPITECH PROJECT, 2022
** ComponentDroppable.cpp
** File description:
** ComponentDroppable.cpp
*/

#include "ComponentDroppable.hpp"

bool ComponentDroppable::getAbleToBePicked() const
{
    return (_ableToBePicked);
}

void ComponentDroppable::setAbleToBePicked(bool ableToBePicked)
{
    _ableToBePicked = ableToBePicked;
}