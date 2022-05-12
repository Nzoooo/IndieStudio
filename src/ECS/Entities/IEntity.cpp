/*
** EPITECH PROJECT, 2022
** Project
** File description:
** IEntity
*/

#include "IEntity.hpp"

ecs::IEntity::~IEntity()
{
    for (auto *it : _components)
        delete it;
}
