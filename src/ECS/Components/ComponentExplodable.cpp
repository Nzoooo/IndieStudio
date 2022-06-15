/*
** EPITECH PROJECT, 2022
** ComponentExplodable.cpp
** File description:
** ComponentExplodable.cpp
*/

#include "ComponentExplodable.hpp"

std::size_t ComponentExplodable::getBlastRange() const
{
    return (_blastRange);
}

bool ComponentExplodable::getReadyToExplode() const
{
    return (_readyToExplode);
}

float ComponentExplodable::getTimeLeft() const
{
    return (this->_timeLeft);
}

void ComponentExplodable::setBlastRange(std::size_t blastRange)
{
    _blastRange = blastRange;
}

void ComponentExplodable::setReadyToExplode(bool readyToExplode)
{
    _readyToExplode = readyToExplode;
}

void ComponentExplodable::setTimeLeft(float timeLeft)
{
    this->_timeLeft = timeLeft;
}
