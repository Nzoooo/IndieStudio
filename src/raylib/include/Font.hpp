/*
** EPITECH PROJECT, 2022
** Font
** File description:
** Font
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib
{
    class Font : public ::Font {
      public:
        Font();
        Font(const std::string &fileName);
        Font(const Font &other) = delete;
        ~Font();

        ::Vector2 MeasureText(const std::string &text, float fontSize, float spacing);
        void DrawText(const std::string &text, ::Vector2 position, float fontSize, float spacing, ::Color tint);
        void DrawText(const std::string &text, ::Vector2 position, ::Vector2 origin, float rotation, float fontSize, float spacing, ::Color tint);
        void Load(const std::string &fileName);
        void Unload();

      protected:
      private:
    };
} // namespace raylib
