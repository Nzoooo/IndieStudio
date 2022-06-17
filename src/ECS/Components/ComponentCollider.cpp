/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentCollider
*/

#include "ComponentCollider.hpp"

raylib::BoundingBox &ComponentCollider::getCollision()
{
    return (_collision);
}

void ComponentCollider::setCollision(raylib::BoundingBox collision)
{
    _collision = collision;
}

void ComponentCollider::add_vector(bool direction)
{
    _direction.push_back(direction);
}

bool ComponentCollider::getVector(ComponentCollider::direction direct)
{
    return (_direction.at(direct));
}
