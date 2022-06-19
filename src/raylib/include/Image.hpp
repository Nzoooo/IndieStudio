/*
** EPITECH PROJECT, 2022
** Image
** File description:
** Image
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib
{
    class Image : public ::Image {
      public:
        Image() = default;
        Image(const std::string &fileName);
        Image(const std::string &fileName, int width, int height, int format, int headerSize);
        Image(::Texture2D &texture);
        Image(const Image &other) = delete;
        ~Image();

        void Load(const std::string &fileName);
        void Load(const std::string &fileName, int width, int height, int format, int headerSize);
        void Load(::Texture2D &texture);
        void Unload();

        void ImageRotateCW(); // Rotate image clockwise 90deg

      protected:
      private:
    };
} // namespace raylib
