/*
** EPITECH PROJECT, 2022
** Font
** File description:
** Font
*/

#include "../include/Font.hpp"

raylib::Font::Font()
{
    ::Font font = ::GetFontDefault();

    baseSize = font.baseSize;
    glyphCount = font.glyphCount;
    glyphPadding = font.glyphPadding;
    texture = font.texture;
    recs = font.recs;
    glyphs = font.glyphs;
}

raylib::Font::Font(const std::string &fileName)
{
    Load(fileName);
}

raylib::Font::~Font()
{
    Unload();
}

void raylib::Font::Unload()
{
    ::UnloadFont(*this);
}

void raylib::Font::Load(const std::string &fileName)
{
    ::Font font = ::LoadFont(fileName.c_str());

    baseSize = font.baseSize;
    glyphCount = font.glyphCount;
    glyphPadding = font.glyphPadding;
    texture = font.texture;
    recs = font.recs;
    glyphs = font.glyphs;
}

::Vector2 raylib::Font::MeasureText(const std::string &text, float fontSize, float spacing)
{
    return (::MeasureTextEx(*this, text.c_str(), fontSize, spacing));
}

void raylib::Font::DrawText(const std::string &text, ::Vector2 position, float fontSize, float spacing, ::Color tint)
{
    ::DrawTextEx(*this, text.c_str(), position, fontSize, spacing, tint);
}

void raylib::Font::DrawText(const std::string &text, ::Vector2 position, ::Vector2 origin, float rotation, float fontSize, float spacing, ::Color tint)
{
    ::DrawTextPro(*this, text.c_str(), position, origin, rotation, fontSize, spacing, tint);
}
