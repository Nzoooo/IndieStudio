/*
** EPITECH PROJECT, 2022
** ComponentCollider.cpp
** File description:
** ComponentCollider.cpp
*/

#include "ComponentCollider.hpp"

bool ComponentCollider::getTakeCollider() const
{
    return (_takeCollider);
}

bool ComponentCollider::getIsCollidable() const
{
    return (_isCollidable);
}

void ComponentCollider::setTakeCollider(bool takeCollider)
{
    _takeCollider = takeCollider;
}

void ComponentCollider::setIsCollidable(bool isCollidable)
{
    _isCollidable = isCollidable;
}