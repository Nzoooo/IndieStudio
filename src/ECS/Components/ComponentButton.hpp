/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentButton
*/

#ifndef COMPONENTBUTTON_HPP_
#define COMPONENTBUTTON_HPP_

#include "../../raylib/include/Texture.hpp"
#include "../../raylib/include/Color.hpp"
#include "../../raylib/include/Vector2.hpp"
#include "../../raylib/include/Rectangle.hpp"
#include "../../raylib/include/Image.hpp"
#include "IComponent.hpp"

class ComponentButton : public ecs::IComponent{
    public:
        ComponentButton(raylib::Vector2 pos, std::string texturePath, std::string buttonText);
        ~ComponentButton();

        void Draw();
    private:
        raylib::Font _font;
        raylib::Rectangle *_rectangle;
        raylib::Texture _texture;
        raylib::Vector2 _pos;
};

#endif /* !COMPONENTBUTTON_HPP_ */