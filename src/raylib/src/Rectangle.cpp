/*
** EPITECH PROJECT, 2022
** Rectangle
** File description:
** Rectangle
*/

#include "../include/Rectangle.hpp"

namespace raylib
{
    Rectangle::Rectangle() : ::Rectangle{0, 0, 0, 0}
    {
    }

    Rectangle::Rectangle(float _x, float _y, float _width, float _height) : ::Rectangle{_x, _y, _width, _height}
    {
    }

    Rectangle::Rectangle(::Vector2 position, ::Vector2 size) : ::Rectangle{position.x, position.y, size.x, size.y}
    {
    }

    Rectangle::Rectangle(const Rectangle &other)
    {
        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;
    }

    Rectangle::~Rectangle()
    {
    }

    void Rectangle::Draw(::Color color)
    {
        ::DrawRectangle(x, y, width, height, color);
    }

    void Rectangle::DrawLines(::Color color)
    {
        ::DrawRectangleLines(x, y, width, height, color);
    }

    void Rectangle::DrawLinesEx(float lineThick, ::Color color)
    {
        ::DrawRectangleLinesEx(*this, lineThick, color);
    }

    void Rectangle::DrawRounded(float roundness, int segments, ::Color color)
    {
        ::DrawRectangleRounded(*this, roundness, segments, color);
    }

    void Rectangle::DrawRoundedLines(float roundness, int segments, float lineThick, ::Color color)
    {
        ::DrawRectangleRoundedLines(*this, roundness, segments, lineThick, color);
    }
} // namespace raylib
