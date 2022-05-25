/*
** EPITECH PROJECT, 2022
** Rectangle
** File description:
** Rectangle
*/

#pragma once

#include "raylib.hpp"

namespace raylib {
    class Rectangle : public ::Rectangle {
        public:
            Rectangle();
            Rectangle(float _x, float _y, float _width, float _height);
            Rectangle(const Rectangle &other);
            ~Rectangle();

            void Draw(int posX, int posY, int width, int height, ::Color color);
            void DrawV(::Vector2 position, ::Vector2 size, ::Color color);
            void DrawRec(::Rectangle rec, ::Color color);
            void DrawLines(int posX, int posY, int width, int height, ::Color color);
            void DrawLinesEx(::Rectangle rec, float lineThick, ::Color color);
            void DrawRounded(::Rectangle rec, float roundness, int segments, ::Color color);
            void DrawRoundedLines(::Rectangle rec, float roundness, int segments, float lineThick, ::Color color);

        protected:
        private:
    };
}
