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

raylib::Texture ComponentCube::getTexture() const
{
    return this->_tex;
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

void ComponentCube::setTexture(const std::string texture)
{
    this->_tex.Load(texture);
}

void ComponentCube::Draw()
{
    if (_tex.IsReady() == true)
        DrawCubeTexture(_tex, _pos, _size.x, _size.y, _size.z, _color);
    else
        DrawCube(_pos, _size.x, _size.y, _size.z, _color);
}

std::string ComponentCube::getTexturePath() const
{
    return (this->_tex.getTexturePath());
}
