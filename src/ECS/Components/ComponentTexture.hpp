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
    ComponentTexture(std::string texturePath, raylib::Vector2 pos) : _pos(pos), _texturePath(texturePath)
    {
        _texture.Load(texturePath);
    };
    ~ComponentTexture() = default;

    raylib::Texture getTexture() const;
    std::string getTexturePath() const;
    raylib::Vector2 getPos() const;
    void Draw();

  private:
    raylib::Texture _texture;
    raylib::Vector2 _pos;
    std::string _texturePath;
};
