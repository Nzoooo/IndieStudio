/*
** EPITECH PROJECT, 2022
** ComponentMusic
** File description:
** ComponentMusic
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Music.hpp"

class ComponentMusic : public ecs::IComponent {
  public:
    ComponentMusic(std::string fileName)
    {
        _music.Load(fileName);
    };
    ~ComponentMusic();

    raylib::Music &getMusic()
    {
        return (_music);
    };

  protected:
  private:
    raylib::Music _music;
};
