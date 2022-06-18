/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentBombs
*/

#include "ComponentBombs.hpp"

std::size_t ComponentBombs::getNbMaxBombs() const
{
    return _max_bombs;
}

void ComponentBombs::setNbMaxBombs(std::size_t max_bombs)
{
    _max_bombs = max_bombs;
}

std::size_t ComponentBombs::getNbCurrBombs() const
{
    return _curr_bombs;
}

void ComponentBombs::setNbCurrBombs(std::size_t curr_bombs)
{
    _curr_bombs = curr_bombs;
}
