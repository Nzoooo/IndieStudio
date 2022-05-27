/*
** EPITECH PROJECT, 2022
** Camera3D.hpp
** File description:
** Camera3D
*/

#pragma once

#include "raylib.hpp"

namespace raylib {
    class Camera3D : public ::Camera3D {
        public:
            Camera3D(::Vector3 _position = {0.0f, 0.0f, 0.0f}, ::Vector3 _target = {0.0f, 0.0f, 0.0f}, ::Vector3 _up = {0.0f, 1.0f, 0.0f}, float _fovy = 0);
            Camera3D(const ::Camera3D &cam);
            ~Camera3D();

            void BeginMode();
            void EndMode();
            void Update();
            void SetMode(int mode);

        protected:
        private:
            void _setCamera3D(const ::Camera3D &cam);
    };
}