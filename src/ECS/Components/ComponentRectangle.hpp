/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentRectangle
*/

#pragma once

#include "../../raylib/include/Color.hpp"
#include "../../raylib/include/Rectangle.hpp"
#include "IComponent.hpp"

class ComponentRectangle : public ecs::IComponent {
  public:
    ComponentRectangle(float x = 0.0, float y = 0.0, float width = 200.0, float height = 75.0) : _color(raylib::Color::White())
    {
        _rectangle = new raylib::Rectangle(x, y, width, height);
    };
    ComponentRectangle(raylib::Rectangle *rectangle) : _rectangle(rectangle){};
    ~ComponentRectangle() = default;

    raylib::Rectangle *getRectangle() const;
    raylib::Color getColor() const;

    void setRectangle(raylib::Rectangle *);
    void setColor(raylib::Color);

  private:
    raylib::Rectangle *_rectangle;
    raylib::Color _color;
};
