/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentKills
*/

#include "ComponentKills.hpp"

ComponentKills::ComponentKills()
{
    this->_nb_kills = 0;
}

std::size_t ComponentKills::getNbKills() const
{
    return (_nb_kills);
}

void ComponentKills::incrNbKills()
{
    _nb_kills++;
}
