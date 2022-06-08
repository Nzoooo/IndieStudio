/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentCube
*/

#ifndef COMPONENTCUBE_HPP_
#define COMPONENTCUBE_HPP_

#include "raylib/include/Vector3.hpp"

class ComponentCube : public ecs::IComponent {
    public:
        ComponentCube(float x, float y, float z) : _color(raylib::Color::White()) {_vector = new raylib::Vector3(x, y, z);};
        ComponentCube(raylib::Vector3 *vector) : _vector(vector) {};
        ~ComponentCube() = default;

        raylib::Vector3 *getVector() const;
        raylib::Color getColor() const;

        void setVector(raylib::Vector3 *);
        void setColor(raylib::Color);

    private:
        raylib::Vector3 *_vector;
        raylib::Color _color;
};

#endif /* !COMPONENTCUBE_HPP_ */
