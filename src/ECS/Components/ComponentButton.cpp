/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentButton
*/

#include "ComponentButton.hpp"

ComponentButton::ComponentButton(raylib::Vector2 pos, std::string buttonText)
{
    this->_pos = pos;
    this->_rectangle = new raylib::Rectangle(1611, 242, 358, 117);
    this->_texture.Load("../assets/menuAsset.png");
    this->_font.Load("../assets/NewAthletic.ttf");
    this->_text = buttonText;
}

void ComponentButton::Draw()
{
    this->_texture.Draw(*this->_rectangle, this->_pos);
    this->_font.DrawText(this->_text, raylib::Vector2(800 / 2.0f - (this->_text.length() * 20) / 2.0f, this->_pos.y + 40.0), 40.0, 3.0, raylib::Color::White());
}

void ComponentButton::setState(bool isActive)
{
    this->_isActive = isActive;
}

bool ComponentButton::getState() const
{
    return (this->_isActive);
}

void ComponentButton::setIdButton(int id)
{
    this->_idButton = id;
}

int ComponentButton::getIdButton() const
{
    return (this->_idButton);
}

void ComponentButton::setTexture(std::string &texturePath)
{
    this->_texture.Load(texturePath);
}
