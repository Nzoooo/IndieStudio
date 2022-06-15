/*
** EPITECH PROJECT, 2022
** Vector3.hpp
** File description:
** Vector
*/

#pragma once

#include <ostream>
#include "raylib.hpp"

namespace raylib
{
    class Vector3 : public ::Vector3 {
      public:
        Vector3();
        Vector3(::Vector3 &vec);
        Vector3(const Vector3 &other);
        Vector3 &operator=(const Vector3 &other);
        Vector3(float _x, float _y, float _z);
        ~Vector3() = default;

        void DrawCube(float width, float height, float length, ::Color color);
        void DrawCube(const ::Vector3 &size, ::Color color);
        void DrawCubeWires(float width, float height, float length, ::Color color);
        void DrawCubeWires(const ::Vector3 &size, ::Color color);
        void DrawCubeTexture(const ::Texture2D &texture, float width, float height, float length, ::Color color);

      private:
        void _setVector3(::Vector3 &vec);
    };
} // namespace raylib

std::ostream &operator<<(std::ostream &os, const raylib::Vector3 &v);
