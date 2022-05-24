/*
** EPITECH PROJECT, 2022
** Vector2.hpp
** File description:
** Vector2.hpp
*/

#pragma once

#include "raylib.hpp"

namespace raylib {
    class Vector2 : public ::Vector2 {
        public:
            Vector2(::Vector2 &vec) {
                _setVector2(vec);
            }
            Vector2(float _x, float _y) {
                x = _x;
                y = _y;
            }
            Vector2() {
                x = 0;
                y = 0;
            }
            Vector2 &operator=(::Vector2 &vector2) {
                _setVector2(vector2);
                return *this;
            }
            ~Vector2();

        private:
            void _setVector2(::Vector2 &vec) {
                x = vec.x;
                y = vec.y;
            }
    };
}
