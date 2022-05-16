/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentMovable
*/

#include "ComponentMovable.hpp"

bool componentMovable::getAbleToMove() const
{
    return this->_ableToMove;
}

void componentMovable::setAbleToMove(bool ableToMove) {
    this->_ableToMove = ableToMove;
}