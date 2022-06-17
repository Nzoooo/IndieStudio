/*
** EPITECH PROJECT, 2022
** ComponentControllable
** File description:
** ComponentControllable
*/

#include "ComponentControllable.hpp"

void ComponentControllable::setGamepadId(int gamepadNumber)
{
    this->_gamepadId = gamepadNumber;
}

int ComponentControllable::getGamepadId()
{
    return (this->_gamepadId);
}
