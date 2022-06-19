/*
** EPITECH PROJECT, 2022
** ComponentCollider
** File description:
** ComponentCollider
*/

#include "ComponentCollider.hpp"

bool ComponentCollider::getIsAbleToCollide() const
{
    return (_isAbleToCollide);
}

void ComponentCollider::setIsAbleToCollide(bool isAbleToCollide)
{
    _isAbleToCollide = isAbleToCollide;
}

void ComponentCollider::setTimeNonCollide()
{
    _timeNonCollide = std::chrono::system_clock::now();
}

std::chrono::time_point<std::chrono::system_clock> ComponentCollider::getTimeNonCollide() const
{
    return (_timeNonCollide);
}
