/*
** EPITECH PROJECT, 2022
** BoundingBox
** File description:
** BoundingBox
*/

#pragma once

#include "raylib.hpp"

class BoundingBox : public ::BoundingBox {
    public:
        BoundingBox() = default;
        BoundingBox(::Vector3 _min, ::Vector3 _max);
        ~BoundingBox();

        void Draw();
        bool checkCollision(::BoundingBox &box2);
        bool checkCollision(::Vector3 center, float radius);

    protected:
    private:
};
