/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentCube
*/

#include "ComponentCube.hpp"

raylib::Vector3 ComponentCube::getPos() const
{
    return this->_pos;
}

raylib::Vector3 ComponentCube::getSize() const
{
    return this->_size;
}

raylib::Color ComponentCube::getColor() const
{
    return this->_color;
}

void ComponentCube::setPos(raylib::Vector3 pos)
{
    this->_pos = pos;
}

void ComponentCube::setSize(raylib::Vector3 size)
{
    this->_size = size;
}

void ComponentCube::setColor(raylib::Color color)
{
    this->_color = color;
}

void ComponentCube::Draw()
{
    _pos.DrawCube(_size, _color);
}
