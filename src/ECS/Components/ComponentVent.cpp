/*
** EPITECH PROJECT, 2022
** ComponentVent.cpp
** File description:
** ComponentVent.cpp
*/

#include "ComponentVent.hpp"

ComponentVent::ComponentVent() : _pairedVent(nullptr)
{
}

void ComponentVent::pairVent(ecs::IEntity *ventToPair)
{
    _pairedVent = ventToPair;
}

ecs::IEntity *ComponentVent::getPairedVent()
{
    return (_pairedVent);
}
