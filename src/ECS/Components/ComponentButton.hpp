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
#include "../../raylib/include/Font.hpp"
#include "IComponent.hpp"

class ComponentButton : public ecs::IComponent{
    public:
        ComponentButton(raylib::Vector2 pos, std::string buttonText);
        ~ComponentButton();

        void Draw();
        void setState(bool isActive);
        bool getState() const;
        void setIdButton(int id);
        int getIdButton() const;
        void setTexture(std::string &texturePath);
        raylib::Rectangle *getRectangle() const;
        raylib::Vector2 getPos() const;
    private:
        raylib::Font _font;
        raylib::Rectangle *_rectangle;
        raylib::Texture _texture;
        raylib::Vector2 _pos;
        std::string _text;
        bool _isActive = false;
        int _idButton;
};

#endif /* !COMPONENTBUTTON_HPP_ */
