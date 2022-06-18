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

void ComponentCollider::add_vector(bool direct)
{
    _direction.at(0) = direct;
}

bool ComponentCollider::getVector(ComponentCollider::side direct)
{
    return (_direction.at(direct));
}

void ComponentCollider::clearVector()
{
    this->_direction.clear();

    fill(_direction.begin(), _direction.end(), 0);
}
