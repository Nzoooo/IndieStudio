/*
** EPITECH PROJECT, 2022
** Texture.cpp
** File description:
** Texture
*/

#include "../include/Texture.hpp"
#include "../include/RaylibException.hpp"

raylib::Texture::Texture() : ::Texture{0, 0, 0, 0, 0}
{
}

raylib::Texture::Texture(const ::Texture &texture)
{
    _setTexture(texture);
}

raylib::Texture::Texture(const raylib::Texture &other)
{
    _setTexture(other);
    _texturePath = other.getTexturePath();
}

raylib::Texture::Texture(const ::Image &image)
{
    if (!Load(image)) {
        throw RaylibException("Failed to load Texture from Image");
    }
}

raylib::Texture::Texture(const ::Image &image, int layout)
{
    if (!Load(image, layout)) {
        throw RaylibException("Failed to load Texture from Cubemap");
    }
}

bool raylib::Texture::Load(const ::Image &image)
{
    _setTexture(::LoadTextureFromImage(image));
    return IsReady();
}

bool raylib::Texture::Load(const ::Image &image, int layout)
{
    _setTexture(::LoadTextureCubemap(image, layout));
    return IsReady();
}

bool raylib::Texture::Load(const std::string &fileName)
{
    _setTexture(::LoadTexture(fileName.c_str()));
    _texturePath = fileName;
    return IsReady();
}

bool raylib::Texture::IsReady() const
{
    return (id != 0);
}

void raylib::Texture::Unload()
{
    ::UnloadTexture(*this);
}

void raylib::Texture::Update(::Rectangle rec, const void *pixels)
{
    ::UpdateTextureRec(*this, rec, pixels);
}

void raylib::Texture::Update(const void *pixels)
{
    ::UpdateTexture(*this, pixels);
}

void raylib::Texture::SetFilter(int filterMode)
{
    ::SetTextureFilter(*this, filterMode);
}

void raylib::Texture::SetWrap(WrapMode wrapMode)
{
    ::SetTextureWrap(*this, wrapMode);
}

void raylib::Texture::Draw(::Vector2 position, ::Color tint)
{
    ::DrawTextureV(*this, position, tint);
}

void raylib::Texture::Draw(::Vector2 position, float rotation, float scale, ::Color tint)
{
    ::DrawTextureEx(*this, position, rotation, scale, tint);
}

void raylib::Texture::Draw(::Rectangle source, ::Vector2 position, ::Color tint)
{
    ::DrawTextureRec(*this, source, position, tint);
}

void raylib::Texture::SetShapes(::Rectangle &source)
{
    ::SetShapesTexture(*this, source);
}

void raylib::Texture::SetShaderValue(::Shader &shader, int locIndex)
{
    ::SetShaderValueTexture(shader, locIndex, *this);
}

std::string raylib::Texture::getTexturePath() const
{
    return (this->_texturePath);
}

void raylib::Texture::_setTexture(const ::Texture &texture)
{
    id = texture.id;
    width = texture.width;
    height = texture.height;
    mipmaps = texture.mipmaps;
    format = texture.format;
}
