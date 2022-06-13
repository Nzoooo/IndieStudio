/*
** EPITECH PROJECT, 2022
** Rectangle
** File description:
** Rectangle
*/

#pragma once

#include "raylib.hpp"

namespace raylib
{
    class Rectangle : public ::Rectangle {
      public:
        Rectangle();
        Rectangle(float _x, float _y, float _width, float _height);
        Rectangle(::Vector2 position, ::Vector2 size);
        Rectangle(const Rectangle &other);
        ~Rectangle();

        void Draw(::Color color);
        void DrawLines(::Color color);
        void DrawLinesEx(float lineThick, ::Color color);
        void DrawRounded(float roundness, int segments, ::Color color);
        void DrawRoundedLines(float roundness, int segments, float lineThick, ::Color color);

      protected:
      private:
    };
} // namespace raylib
