/*
** EPITECH PROJECT, 2022
** Project
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** IEntity
*/

#include "IEntity.hpp"

ecs::IEntity::~IEntity()
{
    for (auto *it : _components)
        delete it;
}

std::vector<ecs::IComponent *> &ecs::IEntity::getAllComponents()
{
    return (_components);
}

void ecs::IEntity::setLabel(std::string label)
{
    _label = label;
}

std::string ecs::IEntity::getLabel() const
{
    return (_label);
}
