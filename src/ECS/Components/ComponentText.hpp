/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentText
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Font.hpp"
#include "raylib/include/Color.hpp"
#include "raylib/include/Vector2.hpp"

class ComponentText : public ecs::IComponent {
    public:
        ComponentText
        (std::string font, std::string text, raylib::Vector2 pos, size_t size, raylib::Color color) : _text(text), _pos(pos), _size(size), _color(color) {_font.Load(font);};
        ~ComponentText() = default;

        void Draw();
    private:
        raylib::Font _font;
        std::string _text;
        raylib::Vector2 _pos;
        size_t _size;
        raylib::Color _color;

};
