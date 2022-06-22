/*
** EPITECH PROJECT, 2022
** ComponentEmote.hpp
** File description:
** ComponentEmote.hpp
*/

#pragma once

#include "IComponent.hpp"
#include <vector>
#include <chrono>
#include "raylib/include/Texture.hpp"
#include "raylib/include/Vector2.hpp"

class ComponentEmote : public ecs::IComponent {
    public:
        ComponentEmote(raylib::Vector2 pos);
        ~ComponentEmote() = default;

        void Draw();
        void setEmote(std::size_t index);

    protected:
    private:
        std::vector<std::pair<bool, raylib::Texture>> _emote;
        std::chrono::time_point<std::chrono::system_clock> _displayTime;
        raylib::Vector2 _pos;
};
