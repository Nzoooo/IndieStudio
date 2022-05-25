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

void ComponentCollider::setTakeCollider(bool takeCollider)
{
    _takeCollider = takeCollider;
}