/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentButton
*/

#include "ComponentButton.hpp"

ComponentButton::ComponentButton(raylib::Vector2 pos, std::string texturePath, std::string buttonText)
{
    this->_pos = pos;
    this->_rectangle = new raylib::Rectangle(3221, 481, 715, 244);
    this->_texture.Load(texturePath);
}

void ComponentButton::Draw()
{
    this->_texture.Draw(this->_pos);
}

