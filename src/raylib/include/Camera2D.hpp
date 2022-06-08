/*
** EPITECH PROJECT, 2022
** Camera2D.hpp
** File description:
** Camera.hpp
*/

#pragma once

#include "raylib.hpp"

namespace raylib
{
    class Camera2D : public ::Camera2D {
      public:
        Camera2D();
        Camera2D(const ::Camera2D &camera);
        Camera2D(::Vector2 _offset, ::Vector2 _target);
        ~Camera2D() = default;

        void BeginMode();
        void EndMode();

      protected:
      private:
        void _setCamera2D(const ::Camera2D &cam);
    };
} // namespace raylib
