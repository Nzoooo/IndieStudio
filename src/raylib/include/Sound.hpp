/*
** EPITECH PROJECT, 2022
** Sound
** File description:
** Sound
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib
{
    class Sound : public ::Sound {
      public:
        Sound() = default;
        Sound(const std::string &fileName);
        Sound(const Sound &other) = delete;
        ~Sound();

        void Load(const std::string &fileName);
        void Unload();
        void Play();
        void PlayMulti();
        void Resume();
        void Pause();
        void Stop();
        bool IsPlaying();
        void SetVolume(float volume);
        void SetPitch(float pitch);

      protected:
      private:
    };
} // namespace raylib
