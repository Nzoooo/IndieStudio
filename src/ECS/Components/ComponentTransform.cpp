/*
** EPITECH PROJECT, 2022
** ComponentTransform.cpp
** File description:
** ComponentTransform.cpp
*/

#include "ComponentTransform.hpp"

std::size_t ComponentTransform::getHeight() const
{
    return (_height);
}

std::size_t ComponentTransform::getWidth() const
{
    return (_width);
}

int ComponentTransform::getPosX() const
{
    return (_posX);
}

int ComponentTransform::getPosY() const
{
    return (_posY);
}

void ComponentTransform::setHeight(std::size_t height)
{
    _height = height;
}

void ComponentTransform::setWidth(std::size_t width)
{
    _width = width;
}

void ComponentTransform::setPosX(int posX)
{
    _posX = posX;
}

void ComponentTransform::setPosY(int posY)
{
    _posY = posY;
}
