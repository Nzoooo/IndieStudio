/*
** EPITECH PROJECT, 2022
** Model
** File description:
** Model
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib
{
    class Model : public ::Model {
      public:
        Model();
        Model(const Model &other) = delete;
        ~Model();

        void Load(const std::string &fileName);
        void Load(::Mesh &mesh);
        void Unload();
        void UnloadKeepMeshes();
        ::BoundingBox GetBoundingBox();
        void Draw(::Vector3 position, float scale, ::Color tint);
        void DrawEx(::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint);
        void UpdateAnimation(::ModelAnimation &anim, int frame);
        bool IsModelAnimationValid(::ModelAnimation &anim) const;

      protected:
      private:
    };
} // namespace raylib
