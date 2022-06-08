/*
** EPITECH PROJECT, 2022
** ComponentDrawable
** File description:
** ComponentDrawable
*/

#include "ComponentDrawable.hpp"

bool ComponentDrawable::getIsDrawable2D() const
{
    return (this->_isDrawable2D);
}

void ComponentDrawable::setIsDrawable2D(bool isDrawable2D)
{
    this->_isDrawable2D = isDrawable2D;
}

bool ComponentDrawable::getIsDrawable3D() const
{
    return (this->_isDrawable3D);
}

void ComponentDrawable::setIsDrawable3D(bool isDrawable3D)
{
    this->_isDrawable3D = isDrawable3D;
}
