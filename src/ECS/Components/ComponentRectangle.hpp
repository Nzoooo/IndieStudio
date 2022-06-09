/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentRectangle
*/

#pragma once

#include "IComponent.hpp"
#include "../../raylib/include/Rectangle.hpp"
#include "../../raylib/include/Color.hpp"

class ComponentRectangle : public ecs::IComponent {
    public:
        ComponentRectangle
        (float x = 0.0, float y = 0.0, float width = 200.0, float height = 75.0, raylib::Color color = raylib::Color::White()) : _color(color) {_rectangle = new raylib::Rectangle(x, y, width, height);};
        ComponentRectangle(raylib::Rectangle *rectangle, raylib::Color color = raylib::Color::White()) : _rectangle(rectangle), _color(color) {};
        ~ComponentRectangle() = default;

        raylib::Rectangle *getRectangle() const;
        raylib::Color getColor() const;

        void setRectangle(raylib::Rectangle *);
        void setColor(raylib::Color);

        void Draw();

    private:
        raylib::Rectangle *_rectangle;
        raylib::Color _color;
};
