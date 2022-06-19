/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentText
*/

#include "ComponentText.hpp"

void ComponentText::Draw()
{
    this->_font.DrawText(this->_text, this->_pos, this->_size, 3.0, this->_color);
}

void ComponentText::setText(std::string text)
{
    this->_text = text;
}

std::string ComponentText::getLabel() const
{
    return (this->_label);
}

std::string ComponentText::getText() const
{
    return (this->_text);
}
