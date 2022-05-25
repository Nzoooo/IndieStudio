/*
** EPITECH PROJECT, 2022
** BoundingBox
** File description:
** BoundingBox
*/

#include "include/BoundingBox.hpp"

BoundingBox(::Vector3 _min, ::Vector3 _max)
{
    min = _min;
    max = _max;
}

BoundingBox::~BoundingBox()
{
}

raylib::BoundingBox::Draw(::Color color)
{
    DrawBoundingBox(*this, color);
}

bool raylib::BoundingBox::checkCollision(::BoundingBox &box2)
{
    return (::CheckCollisionBoxes(*this, box2));
}

bool raylib::BoundingBox::checkCollision(::Vector3 center, float radius)
{
    return (::CheckCollisionBoxSphere(*this, center, radius));
}
