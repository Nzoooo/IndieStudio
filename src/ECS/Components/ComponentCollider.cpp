/*
** EPITECH PROJECT, 2022
** ComponentCollider.cpp
** File description:
** ComponentCollider.cpp
*/

#include "ComponentCollider.hpp"

bool ComponentCollider::getAbleToTakeCollider() const
{
    return (_ableToTakeCollider);
}

void ComponentCollider::setAbleToTakeCollider(bool ableToTakeCollider)
{
    _ableToTakeCollider = ableToTakeCollider;
}