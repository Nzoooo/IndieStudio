/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentRectangle
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Color.hpp"
#include "raylib/include/Rectangle.hpp"
#include "raylib/include/Vector2.hpp"

class ComponentRectangle : public ecs::IComponent {
  public:
    ComponentRectangle(float x = 0.0, float y = 0.0, float width = 200.0, float height = 75.0, raylib::Color color = raylib::Color::White()) : _color(color)
    {
        _pos.x = x;
        _pos.y = y;
        _size.x = width;
        _size.y = height;
        _rectangle = new raylib::Rectangle(x, y, width, height);
    };
    ComponentRectangle(raylib::Rectangle *rectangle, raylib::Color color = raylib::Color::White()) : _rectangle(rectangle), _color(color){};
    ~ComponentRectangle() = default;

    raylib::Rectangle *getRectangle() const;
    raylib::Color getColor() const;
    raylib::Vector2 getPos() const;
    raylib::Vector2 getSize() const;

    void setRectangle(raylib::Rectangle *);
    void setColor(raylib::Color);

    void Draw();

  private:
    raylib::Vector2 _pos;
    raylib::Vector2 _size;
    raylib::Rectangle *_rectangle;
    raylib::Color _color;
};
