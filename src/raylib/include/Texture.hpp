/*
** EPITECH PROJECT, 2022
** Texture.hpp
** File description:
** texture
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib
{
    class Texture : public ::Texture {
      public:
        typedef enum {
            TEXTURE_WRAP_REPEAT = 0,    // Repeats texture in tiled mode
            TEXTURE_WRAP_CLAMP,         // Clamps texture to edge pixel in tiled mode
            TEXTURE_WRAP_MIRROR_REPEAT, // Mirrors and repeats the texture in tiled mode
            TEXTURE_WRAP_MIRROR_CLAMP   // Mirrors and clamps to border the texture in tiled mode
        } WrapMode;

        Texture();
        Texture(const ::Image &image, int layout);
        Texture(const ::Image &image);
        Texture(const Texture &other);
        Texture(const ::Texture &texture);

        void SetShaderValue(::Shader &shader, int locIndex);
        void SetShapes(::Rectangle &source);
        void Draw(::Vector2 position, float rotation, float scale = 1.0f, ::Color tint = {255, 255, 255, 255});
        void Draw(::Vector2 position, ::Color tint = {255, 255, 255, 255});
        void Draw(::Rectangle source, ::Vector2 position, ::Color tint = {255, 255, 255, 255});
        void SetWrap(WrapMode wrapMode);
        void SetFilter(int filterMode);
        void Update(::Rectangle rec, const void *pixels);
        void Update(const void *pixels);
        void Unload();
        bool IsReady() const;
        bool Load(const std::string &fileName);
        bool Load(const ::Image &image, int layout);
        bool Load(const ::Image &image);
        std::string getTexturePath() const;

      private:
        void _setTexture(const ::Texture &texture);
        std::string _texturePath;
    };
} // namespace raylib
