/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentRectangle
*/

#include "ComponentRectangle.hpp"

raylib::Rectangle *ComponentRectangle::getRectangle() const
{
    return (this->_rectangle);
}

raylib::Color ComponentRectangle::getColor() const
{
    return (this->_color);
}

void ComponentRectangle::setRectangle(raylib::Rectangle *rectangle)
{
    this->_rectangle = rectangle;
}

void ComponentRectangle::setColor(raylib::Color color)
{
    this->_color = color;
}

void ComponentRectangle::Draw()
{
    this->_rectangle->Draw(this->_color);
}
raylib::Vector2 ComponentRectangle::getPos() const
{
    return _pos;
}

raylib::Vector2 ComponentRectangle::getSize() const
{
    return _size;
}
