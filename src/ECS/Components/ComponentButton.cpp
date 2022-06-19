/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentButton
*/

#include "ComponentButton.hpp"

ComponentButton::ComponentButton(raylib::Vector2 pos, std::string buttonText, raylib::Vector2 posText, float fontSize)
{
    this->_pos.x = pos.x;
    this->_pos.y = pos.y;
    this->_rectangleUnactive = new raylib::Rectangle(1611, 242, 358, 117);
    this->_rectangleActive = new raylib::Rectangle(1611, 395, 358, 117);
    this->_texture.Load("assets/menuAsset.png");
    this->_font.Load("assets/NewAthletic.ttf");
    this->_text = buttonText;
    if (posText.x == -1.0f && posText.y == -1.0f)
        this->_posText = raylib::Vector2(1920 / 2.0f - (this->_text.length() * 18) / 2.0f, this->_pos.y + 40.0);
    else
        this->_posText = posText;
    this->_fontSize = fontSize;
}

void ComponentButton::Draw()
{
    if (this->_isActive == true)
        this->_texture.Draw(*this->_rectangleActive, this->_pos);
    else
        this->_texture.Draw(*this->_rectangleUnactive, this->_pos);
    this->_font.DrawText(this->_text, this->_posText, this->_fontSize, 3.0, raylib::Color::White());
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

raylib::Vector2 ComponentButton::getPos() const
{
    return (this->_pos);
}

raylib::Rectangle *ComponentButton::getRectangleActive() const
{
    return (this->_rectangleActive);
}

raylib::Rectangle *ComponentButton::getRectangleUnactive() const
{
    return (this->_rectangleUnactive);
}

void ComponentButton::setText(std::string text)
{
    this->_text = text;
}

std::string ComponentButton::getText() const
{
    return (this->_text);
}
