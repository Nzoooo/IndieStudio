/*
** EPITECH PROJECT, 2022
** ComponentExplosion
** File description:
** ComponentExplosion
*/

#include "ComponentExplosion.hpp"

std::string ComponentExplosion::getLabelPlayerOfBomb()
{
    return (_labelPlayerOfBomb);
}

bool ComponentExplosion::getReadyToExplode() const
{
    return (_readyToExplode);
}

float ComponentExplosion::getTimeLeft() const
{
    return (this->_timeLeft);
}

void ComponentExplosion::setReadyToExplode(bool readyToExplode)
{
    _readyToExplode = readyToExplode;
}

void ComponentExplosion::setTimeLeft(float timeLeft)
{
    this->_timeLeft = timeLeft;
}
