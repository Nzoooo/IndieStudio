/*
** EPITECH PROJECT, 2022
** Color
** File description:
** Color
*/

#pragma once

#include <ostream>
#include "raylib.hpp"

namespace raylib
{
    class Color : public ::Color {
      public:
        Color();
        Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255);
        ~Color();

        static Color LightGray();
        static Color Gray();
        static Color DarkGray();
        static Color Yellow();
        static Color Gold();
        static Color Orange();
        static Color Pink();
        static Color Red();
        static Color Maroon();
        static Color Green();
        static Color Lime();
        static Color DarkGreen();
        static Color SkyBlue();
        static Color Blue();
        static Color DarkBlue();
        static Color Purple();
        static Color Violet();
        static Color DarkPurple();
        static Color Beige();
        static Color Brown();
        static Color DarkBrown();
        static Color White();
        static Color Black();
        static Color Blank();
        static Color Magenta();
        static Color RayWhite();

      protected:
      private:
    };
} // namespace raylib

std::ostream &operator<<(std::ostream &os, const raylib::Color &v);
