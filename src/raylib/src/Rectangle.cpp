/*
** EPITECH PROJECT, 2022
** Rectangle
** File description:
** Rectangle
*/

#include "../include/Rectangle.hpp"

namespace raylib {
    Rectangle::Rectangle() : ::Rectangle{0, 0, 0, 0}
    {
    }

    Rectangle::Rectangle(float _x, float _y, float _width, float _height) :
    ::Rectangle{_x, _y, _width, _height}
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

    void Rectangle::Draw(int posX, int posY, int _width, int _height, ::Color color)
    {
        ::DrawRectangle(posX, posY, _width, _height, color);
    }

    void Rectangle::DrawV(::Vector2 position, ::Vector2 size, ::Color color)
    {
        ::DrawRectangleV(position, size, color);
    }

    void Rectangle::DrawRec(::Rectangle rec, ::Color color)
    {
        ::DrawRectangleRec(rec, color);
    }

    void Rectangle::DrawLines(int posX, int posY, int _width, int _height, ::Color color)
    {
        ::DrawRectangleLines(posX, posY, _width, _height, color);
    }

    void Rectangle::DrawLinesEx(::Rectangle rec, float lineThick, ::Color color)
    {
        ::DrawRectangleLinesEx(rec, lineThick, color);
    }

    void Rectangle::DrawRounded(::Rectangle rec, float roundness, int segments, ::Color color)
    {
        ::DrawRectangleRounded(rec, roundness, segments, color);
    }

    void Rectangle::DrawRoundedLines(::Rectangle rec, float roundness, int segments, float lineThick, ::Color color)
    {
        ::DrawRectangleRoundedLines(rec, roundness, segments, lineThick, color);
    }
}
