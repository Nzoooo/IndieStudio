/*
** EPITECH PROJECT, 2022
** Color
** File description:
** Color
*/

#include "../include/Color.hpp"

namespace raylib
{
    Color::Color() : ::Color{255, 255, 255, 255}
    {
    }

    Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : ::Color{red, green, blue, alpha}
    {
    }

    Color::~Color()
    {
    }

    Color Color::LightGray()
    {
        return LIGHTGRAY;
    }

    Color Color::Gray()
    {
        return GRAY;
    }

    Color Color::DarkGray()
    {
        return DARKGRAY;
    }

    Color Color::Yellow()
    {
        return YELLOW;
    }

    Color Color::Gold()
    {
        return GOLD;
    }

    Color Color::Orange()
    {
        return ORANGE;
    }

    Color Color::Pink()
    {
        return PINK;
    }

    Color Color::Red()
    {
        return RED;
    }

    Color Color::Maroon()
    {
        return MAROON;
    }

    Color Color::Green()
    {
        return GREEN;
    }

    Color Color::Lime()
    {
        return LIME;
    }

    Color Color::DarkGreen()
    {
        return DARKGREEN;
    }

    Color Color::SkyBlue()
    {
        return SKYBLUE;
    }

    Color Color::Blue()
    {
        return BLUE;
    }

    Color Color::DarkBlue()
    {
        return DARKBLUE;
    }

    Color Color::Purple()
    {
        return PURPLE;
    }

    Color Color::Violet()
    {
        return VIOLET;
    }

    Color Color::DarkPurple()
    {
        return DARKPURPLE;
    }

    Color Color::Beige()
    {
        return BEIGE;
    }

    Color Color::Brown()
    {
        return BROWN;
    }

    Color Color::DarkBrown()
    {
        return DARKBROWN;
    }

    Color Color::White()
    {
        return WHITE;
    }

    Color Color::Black()
    {
        return BLACK;
    }

    Color Color::Blank()
    {
        return BLANK;
    }

    Color Color::Magenta()
    {
        return MAGENTA;
    }

    Color Color::RayWhite()
    {
        return RAYWHITE;
    }
} // namespace raylib

std::ostream &operator<<(std::ostream &os, const raylib::Color &c)
{
    return os << "(" << static_cast<int>(c.r) << "; " << static_cast<int>(c.g) << "; " << static_cast<int>(c.b) << "; " << static_cast<int>(c.a) << ")";
}
