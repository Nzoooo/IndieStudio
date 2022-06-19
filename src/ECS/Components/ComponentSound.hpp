/*
** EPITECH PROJECT, 2022
** ComponentSound
** File description:
** ComponentSound
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Sound.hpp"

class ComponentSound : public ecs::IComponent {
  public:
    ComponentSound(std::string fileName)
    {
        _sound.Load(fileName);
    };
    ~ComponentSound();

    raylib::Sound &getSound()
    {
        return (_sound);
    };

  protected:
  private:
    raylib::Sound _sound;
};
