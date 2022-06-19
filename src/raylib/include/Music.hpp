/*
** EPITECH PROJECT, 2022
** Music
** File description:
** Music
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib
{
    class Music : public ::Music {
      public:
        Music() = default;
        Music(const std::string &fileName);
        Music(const Music &other) = delete;
        ~Music();

        void Load(const std::string &fileName);
        void Unload();
        void Play();
        void Resume();
        void Pause();
        void Stop();
        bool IsPlaying();
        void SetVolume(float volume);
        void SetPitch(float pitch);
        void SeekMusic(float position);
        float GetTimeLength();
        float GetTimePlayed();
        void Update();

      protected:
      private:
    };
} // namespace raylib
