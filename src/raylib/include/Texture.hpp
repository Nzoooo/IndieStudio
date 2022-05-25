/*
** EPITECH PROJECT, 2022
** Texture.hpp
** File description:
** texture
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib {
    class Texture : public ::Texture {
        public:
            Texture();
            Texture(::Image &image, int layout);
            Texture &operator=(const Texture &other);
            Texture(const Texture &other);
            Texture(::Texture &texture);

            Texture &SetShaderValue(::Shader& shader, int locIndex);
            Texture &SetShapes(::Rectangle& source);
            Texture &Draw(::Vector2 position, float rotation, float scale = 1.0f,
                            ::Color tint = {255, 255, 255, 255});
            Texture &Draw(::Vector2 position, ::Color tint = {255, 255, 255, 255});
            Texture &SetWrap(int wrapMode);
            Texture &SetFilter(int filterMode);
            Texture &Update(::Rectangle rec, void *pixels);
            Texture &Update(void *pixels);
            bool Unload();
            bool IsReady() const;
            bool Load(std::string &fileName);
            bool Load(::Image &image, int layout);
            bool Load(::Image &image);


        private:
            void _setTexture(::Texture &texture);
    };
}