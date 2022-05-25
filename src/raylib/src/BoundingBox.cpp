/*
** EPITECH PROJECT, 2022
** BoundingBox
** File description:
** BoundingBox
*/

#include "../include/BoundingBox.hpp"

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
