/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentTexture
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Color.hpp"
#include "raylib/include/Texture.hpp"
#include "raylib/include/Vector2.hpp"

class ComponentTexture : public ecs::IComponent {
  public:
    ComponentTexture(std::string texturePath, raylib::Vector2 pos, raylib::Vector2 pos2 = {-1.0f, -1.0f})
        : _pos(pos), _oldPos(pos), _pos2(pos2), _pathOldTexture(texturePath)
    {
        _texture.Load(texturePath);
    };
    ~ComponentTexture() = default;

    void setTexture(std::string texturePath);
    raylib::Texture getTexture() const;
    void setPos(raylib::Vector2 pos);
    raylib::Vector2 getPos() const;
    raylib::Vector2 getPos2() const;
    raylib::Vector2 getOldPos() const;
    std::string getPathOldTexture() const;
    void Draw();

  private:
    raylib::Texture _texture;
    raylib::Vector2 _pos;
    raylib::Vector2 _oldPos;
    raylib::Vector2 _pos2;
    std::string _pathOldTexture;
};
