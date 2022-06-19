/*
** EPITECH PROJECT, 2022
** Image
** File description:
** Image
*/

#include "../include/Image.hpp"

namespace raylib
{
    Image::Image(const std::string &fileName)
    {
        Load(fileName);
    }

    Image::Image(const std::string &fileName, int _width, int _height, int _format, int headerSize)
    {
        Load(fileName, _width, _height, _format, headerSize);
    }

    Image::Image(::Texture2D &texture)
    {
        Load(texture);
    }

    Image::~Image()
    {
        Unload();
    }

    void Image::Load(const std::string &fileName)
    {
        ::Image img = ::LoadImage(fileName.c_str());

        data = img.data;
        width = img.width;
        height = img.height;
        mipmaps = img.mipmaps;
        format = img.format;
    }

    void Image::Load(const std::string &fileName, int _width, int _height, int _format, int headerSize)
    {
        ::Image img = ::LoadImageRaw(fileName.c_str(), _width, _height, _format, headerSize);

        data = img.data;
        width = img.width;
        height = img.height;
        mipmaps = img.mipmaps;
        format = img.format;
    }

    void Image::Load(::Texture2D &texture)
    {
        ::Image img = ::LoadImageFromTexture(texture);

        data = img.data;
        width = img.width;
        height = img.height;
        mipmaps = img.mipmaps;
        format = img.format;
    }

    void Image::Unload()
    {
        ::UnloadImage(*this);
    }

    void Image::ImageRotateCW()
    {
        ::ImageRotateCW(this);
    }
} // namespace raylib
