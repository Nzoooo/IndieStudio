/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentCube
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Color.hpp"
#include "raylib/include/Texture.hpp"
#include "raylib/include/Vector3.hpp"

class ComponentCube : public ecs::IComponent {
  public:
    ComponentCube(raylib::Vector3 pos, raylib::Vector3 size, raylib::Color colorCube, raylib::Texture tex)
        : _pos(pos), _size(size), _color(colorCube), _tex(tex){};
    ~ComponentCube() = default;

    raylib::Vector3 getPos() const;
    raylib::Vector3 getSize() const;
    raylib::Texture getTexture() const;
    raylib::Color getColor() const;

    void setPos(raylib::Vector3 pos);
    void setSize(raylib::Vector3 size);
    void setColor(raylib::Color color);
    void setTexture(const std::string texture);
    std::string getTexturePath() const;

    void Draw();

  private:
    raylib::Vector3 _pos;
    raylib::Vector3 _size;
    raylib::Color _color;
    raylib::Texture _tex;
};
