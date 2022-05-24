/*
** EPITECH PROJECT, 2022
** Texture.hpp
** File description:
** texture
*/

#pragma once

#include "raylib.hpp"

namespace raylib {
    class Texture : public ::Texture {
        public:
            Texture() {
                id = 0;
                width = 0;
                height = 0;
                mipmaps = 0;
                format = 0;
            }
            Texture(::Texture &texture) {
                _setTexture(texture);
            }
            Texture(::Image &image) {
                if (!Load(image)) {
                    throw RaylibException("Failed to load Texture from Image");
                }
            }
            Texture(::Image &image, int layout) {
                if (!Load(image, layout)) {
                    throw RaylibException("Failed to load Texture from Cubemap");
                }
            }
            ~Texture();
            bool Load(::Image &image) {
                _setTexture(::LoadTextureFromImage(image));
                return IsReady();
            }
            bool Load(::Image &image, int layout) {
                _setTexture(::LoadTextureCubemap(image, layoutType));
                return IsReady();
            }
            bool Load(std::string &fileName) {
                set(::LoadTexture(fileName.c_str()));
                return IsReady();
            }
            bool IsReady() const {
               return id != 0;
            }
            void Unload() {
                ::UnloadTexture(*this);
            }
            Texture &Update(void *pixels) {
                ::UpdateTexture(*this, pixels);
                return *this;
            }
            Texture &Update(::Rectangle rec, void *pixels) {
                UpdateTextureRec(*this, rec, pixels);
                return *this;
            }
            Texture &SetFilter(int filterMode) {
                ::SetTextureFilter(*this, filterMode);
                return *this;
            }
            Texture &SetWrap(int wrapMode) {
                ::SetTextureWrap(*this, wrapMode);
                return *this;
            }
            Texture &Draw(::Vector2 position, ::Color tint = {255, 255, 255, 255}) {
                ::DrawTextureV(*this, position, tint);
                return *this;
            }
            Texture &Draw(::Vector2 position, float rotation, float scale = 1.0f,
                            ::Color tint = {255, 255, 255, 255}) {
                ::DrawTextureEx(*this, position, rotation, scale, tint);
                return *this;
            }
            Texture &SetShapes(::Rectangle& source) {
                ::SetShapesTexture(*this, source);
                return *this;
            }
            Texture &SetShaderValue(::Shader& shader, int locIndex) {
                ::SetShaderValueTexture(shader, locIndex, *this);
                return *this;
            }

        private:
            void _setTexture(::Texture &texture) {
                id = texture.id;
                width = texture.width;
                height = texture.height;
                mipmaps = texture.mipmaps;
                format = texture.format;
            }
    };
}