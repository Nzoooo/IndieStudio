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

void ComponentExplodable::setBlastRange(std::size_t blastRange)
{
    _blastRange = blastRange;
}
