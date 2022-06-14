/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentTransparency
*/

#include "ComponentTransparency.hpp"

std::size_t ComponentTransparency::getTransparency() const
{
    if (_transparency > 255)
        return (255);
    return _transparency;
}

void ComponentTransparency::setTransparency(std::size_t transparency)
{
    if (transparency > 255)
        transparency = 255;
    _transparency = transparency;
}

raylib::Color ComponentTransparency::sumWithColor(raylib::Color color) const
{
    raylib::Color newColor = color;
    newColor.a = getTransparency();
    return newColor;
}
