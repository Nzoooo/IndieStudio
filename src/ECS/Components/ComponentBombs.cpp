/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentBombs
*/

#include "ComponentBombs.hpp"

std::size_t ComponentBombs::getNbBombs() const
{
    return (_nb_bombs);
}

void ComponentBombs::setNbBombs(std::size_t nb_bombs)
{
    _nb_bombs = nb_bombs;
}
