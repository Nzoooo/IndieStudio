/*
** EPITECH PROJECT, 2022
** ComponentEmote.cpp
** File description:
** ComponentEmote.cpp
*/

#include "ComponentEmote.hpp"
#include <iostream>

ComponentEmote::ComponentEmote(raylib::Vector2 pos) : _pos(pos)
{
    raylib::Texture tex1;
    raylib::Texture tex2;
    raylib::Texture tex3;
    raylib::Texture tex4;

    tex1.Load("assets/emotes/emoteKill.png");
    tex2.Load("assets/emotes/emoteDumb.png");
    tex3.Load("assets/emotes/emoteFine.png");
    tex4.Load("assets/emotes/emoteVent.png");
    _emote.push_back(std::make_pair(false, tex1));
    _emote.push_back(std::make_pair(false, tex2));
    _emote.push_back(std::make_pair(false, tex3));
    _emote.push_back(std::make_pair(false, tex4));
}

void ComponentEmote::Draw()
{
    for (auto &e : _emote) {
        if (e.first && (std::chrono::system_clock::now() - _displayTime) < std::chrono::seconds(2)) {
            e.second.Draw(_pos);
        } else {
            e.first = false;
        }
    }
}

void ComponentEmote::setEmote(std::size_t index)
{
    if (index >= _emote.size())
        return;
    for (auto &e : _emote) {
        e.first = false;
    }
    _emote.at(index).first = true;
    _displayTime = std::chrono::system_clock::now();
}
