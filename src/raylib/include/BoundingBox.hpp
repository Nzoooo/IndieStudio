/*
** EPITECH PROJECT, 2022
** BoundingBox
** File description:
** BoundingBox
*/

#pragma once

#include "raylib.hpp"

namespace raylib
{
    class BoundingBox : public ::BoundingBox {
      public:
        BoundingBox() = default;
        BoundingBox(const BoundingBox &other);
        BoundingBox &operator=(const BoundingBox &other);
        BoundingBox(::Vector3 _min, ::Vector3 _max);
        ~BoundingBox();

        void Draw(::Color color);
        bool checkCollision(::BoundingBox &box2);
        bool checkCollision(::Vector3 center, float radius);

      protected:
      private:
    };
} // namespace raylib
