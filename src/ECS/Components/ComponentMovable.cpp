/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** ComponentMovable
*/

#include "ComponentMovable.hpp"

bool ComponentMovable::getAbleToMove() const
{
    return (this->_ableToMove);
}

void ComponentMovable::setAbleToMove(bool ableToMove)
{
    this->_ableToMove = ableToMove;
}