/*
** EPITECH PROJECT, 2022
** ComponentTransform.hpp
** File description:
** ComponentTransform.hpp
*/

#pragma once

#include <string>
#include "IComponent.hpp"

class ComponentTransform : public ecs::IComponent {
  public:
    ComponentTransform(std::size_t height, std::size_t width, int posX, int posY) : _height(height), _width(width), _posX(posX), _posY(posY){};
    ~ComponentTransform() = default;

    std::size_t getHeight() const;
    std::size_t getWidth() const;
    int getPosX() const;
    int getPosY() const;

    void setHeight(std::size_t height);
    void setWidth(std::size_t width);
    void setPosX(int posX);
    void setPosY(int posY);

  private:
    std::size_t _height;
    std::size_t _width;
    int _posX;
    int _posY;
};
