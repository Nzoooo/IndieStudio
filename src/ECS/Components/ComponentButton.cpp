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
    this->_rectangle = new raylib::Rectangle(1611, 242, 358, 117);
    this->_texture.Load(texturePath);
    this->_font.Load("../assets/NewAthletic.ttf");
    this->_text = buttonText;
}

void ComponentButton::Draw()
{
    this->_texture.Draw(*this->_rectangle, this->_pos);
    this->_font.DrawText(this->_text, (Vector2){800 / 2.0f - (this->_text.length() * 20) / 2.0f, this->_pos.y + 40.0}, 40.0, 3.0, raylib::Color::White());
}

