/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentTexture
*/

#include "ComponentTexture.hpp"

raylib::Texture ComponentTexture::getTexture() const 
{
    return (_texture);
}

void ComponentTexture::Draw()
{
    this->_texture.Draw(this->_pos);
}