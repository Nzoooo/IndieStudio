/*
** EPITECH PROJECT, 2022
** ComponentPickable.cpp
** File description:
** ComponentPickable.cpp
*/

#include "ComponentPickable.hpp"

bool ComponentPickable::getAbleToBePicked() const
{
    return (_ableToBePicked);
}

void ComponentPickable::setAbleToBePicked(bool ableToBePicked)
{
    _ableToBePicked = ableToBePicked;
}