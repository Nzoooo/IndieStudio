/*
** EPITECH PROJECT, 2022
** BoundingBox
** File description:
** BoundingBox
*/

#include "../include/BoundingBox.hpp"

raylib::BoundingBox::BoundingBox(::Vector3 _min, ::Vector3 _max) : ::BoundingBox{_min, _max}
{
}

raylib::BoundingBox::BoundingBox(const BoundingBox &other)
{
    min = other.min;
    max = other.max;
}

raylib::BoundingBox &raylib::BoundingBox::operator=(const BoundingBox &other)
{
    min = other.min;
    max = other.max;
    return *this;
}

raylib::BoundingBox::~BoundingBox()
{
}

void raylib::BoundingBox::Draw(::Color color)
{
    ::DrawBoundingBox(*this, color);
}

bool raylib::BoundingBox::checkCollision(::BoundingBox &box2)
{
    return (::CheckCollisionBoxes(*this, box2));
}

bool raylib::BoundingBox::checkCollision(::Vector3 center, float radius)
{
    return (::CheckCollisionBoxSphere(*this, center, radius));
}
