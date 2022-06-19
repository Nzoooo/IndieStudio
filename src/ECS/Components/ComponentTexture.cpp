/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentTexture
*/

#include "ComponentTexture.hpp"

void ComponentTexture::setTexture(std::string texturePath)
{
    _texture.Load(texturePath);
}

raylib::Texture ComponentTexture::getTexture() const
{
    return (_texture);
}

void ComponentTexture::setPos(raylib::Vector2 pos)
{
    _pos = pos;
}

raylib::Vector2 ComponentTexture::getPos() const
{
    return (_pos);
}

raylib::Vector2 ComponentTexture::getPos2() const
{
    return (_pos2);
}

raylib::Vector2 ComponentTexture::getOldPos() const
{
    return (_oldPos);
}

std::string ComponentTexture::getPathOldTexture() const
{
    return (_pathOldTexture);
}

void ComponentTexture::Draw()
{
    this->_texture.Draw(this->_pos);
}
