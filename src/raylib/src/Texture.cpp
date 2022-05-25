/*
** EPITECH PROJECT, 2022
** Texture.cpp
** File description:
** Texture
*/

#include "../include/Texture.hpp"
#include "../include/RaylibException.hpp"

raylib::Texture::Texture()
{
    id = 0;
    width = 0;
    height = 0;
    mipmaps = 0;
    format = 0;
}

raylib::Texture::Texture(::Texture &texture)
{
    _setTexture(texture);
}

raylib::Texture::Texture(const Texture &other)
{
    id = other.id;
    width = other.width;
    height = other.height;
    mipmaps = other.mipmaps;
    format = other.format;
}

raylib::Texture::Texture &operator=(const Texture &other)
{
    id = other.id;
    width = other.width;
    height = other.height;
    mipmaps = other.mipmaps;
    format = other.format;
    return *this;
}

raylib::Texture::Texture(::Image &image)
{
    if (!Load(image)) {
        throw RaylibException("Failed to load Texture from Image");
    }
}

raylib::Texture::Texture(::Image &image, int layout)
{
    if (!Load(image, layout)) {
        throw RaylibException("Failed to load Texture from Cubemap");
    }
}

bool raylib::Texture::Load(::Image &image)
{
    _setTexture(::LoadTextureFromImage(image));
    return IsReady();
}

bool raylib::Texture::Load(::Image &image, int layout)
{
    _setTexture(::LoadTextureCubemap(image, layoutType));
    return IsReady();
}

bool raylib::Texture::Load(std::string &fileName)
{
    _setTexture(::LoadTexture(fileName.c_str()));
    return IsReady();
}

bool raylib::Texture::IsReady() const
{
    return id != 0;
}

void raylib::Texture::Unload()
{
    ::UnloadTexture(*this);
}

raylib::Texture::Texture &Update(void *pixels)
{
    ::UpdateTexture(*this, pixels);
    return *this;
}

raylib::Texture::Texture &Update(::Rectangle rec, void *pixels)
{
    UpdateTextureRec(*this, rec, pixels);
    return *this;
}

raylib::Texture::Texture &SetFilter(int filterMode)
{
    ::SetTextureFilter(*this, filterMode);
    return *this;
}

raylib::Texture::Texture &SetWrap(int wrapMode)
{
    ::SetTextureWrap(*this, wrapMode);
    return *this;
}

raylib::Texture::Texture &Draw(::Vector2 position, ::Color tint = {255, 255, 255, 255})
{
   ::DrawTextureV(*this, position, tint);
    return *this;
}

raylib::Texture::Texture &Draw(::Vector2 position, float rotation, float scale = 1.0f,
                ::Color tint = {255, 255, 255, 255})
{
    ::DrawTextureEx(*this, position, rotation, scale, tint);
    return *this;
}

raylib::Texture::Texture &SetShapes(::Rectangle& source)
{
    ::SetShapesTexture(*this, source);
    return *this;
}

raylib::Texture::Texture &SetShaderValue(::Shader& shader, int locIndex)
{
    ::SetShaderValueTexture(shader, locIndex, *this);
    return *this;
}

void raylib::Texture::_setTexture(::Texture &texture)
{
    id = texture.id;
    width = texture.width;
    height = texture.height;
    mipmaps = texture.mipmaps;
    format = texture.format;
}