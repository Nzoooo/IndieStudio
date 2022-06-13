/*
** EPITECH PROJECT, 2022
** Camera3D.hpp
** File description:
** Camera3D
*/

#pragma once

#include "raylib.hpp"

namespace raylib
{
    class Camera3D : public ::Camera3D {
      public:
        Camera3D(::Vector3 _position = {0.0f, 0.0f, 0.0f}, ::Vector3 _target = {0.0f, 0.0f, 0.0f}, ::Vector3 _up = {0.0f, 1.0f, 0.0f}, float _fovy = 0);
        Camera3D(const ::Camera3D &cam);
        ~Camera3D() = default;

        void BeginMode();
        void EndMode();
        void Update();
        void SetMode(CameraMode mode);

        static CameraMode CameraCustom();
        static CameraMode CameraFree();
        static CameraMode CameraOrbital();
        static CameraMode CameraFirstPerson();
        static CameraMode CameraThirdPerson();

      protected:
      private:
        void _setCamera3D(const ::Camera3D &cam);
    };
} // namespace raylib
