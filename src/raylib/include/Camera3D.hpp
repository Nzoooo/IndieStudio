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
            Camera3D();
            Camera3D(const ::Camera3D &cam);
            Camera3D(::Vector3 _position);
            ~Camera3D();

            void beginMode();
            void endMode();
            void update();
            void setMode(int mode);

        protected:
        private:
            _setCamera3D(const ::Camera3D camera);
    };
}