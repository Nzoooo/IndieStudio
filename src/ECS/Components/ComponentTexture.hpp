/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentTexture
*/

#pragma once

#include "IComponent.hpp"
#include "../../raylib/include/Texture.hpp"
#include "../../raylib/include/Color.hpp"

class ComponentTexture : public ecs::IComponent {
    public:
        ComponentTexture() = default;
        ComponentTexture(std::string texturePath) {_texture.Load(texturePath);};
        ~ComponentTexture() = default;

        raylib::Texture getTexture() const;
    private:
        raylib::Texture _texture;
};
