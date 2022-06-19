/*
** EPITECH PROJECT, 2022
** Sound
** File description:
** Sound
*/

#include "../include/Sound.hpp"

namespace raylib
{
    Sound::Sound(const std::string &fileName)
    {
        Load(fileName);
    }

    Sound::~Sound()
    {
        Unload();
    }

    void Sound::Load(const std::string &fileName)
    {
        ::Sound sound = LoadSound(fileName.c_str());

        this->frameCount = sound.frameCount;
        this->stream = sound.stream;
    }

    void Sound::Unload()
    {
        ::UnloadSound(*this);
    }

    void Sound::Play()
    {
        ::PlaySound(*this);
    }

    void Sound::PlayMulti()
    {
        ::PlaySoundMulti(*this);
    }

    void Sound::Resume()
    {
        ::ResumeSound(*this);
    }

    void Sound::Pause()
    {
        ::PauseSound(*this);
    }

    void Sound::Stop()
    {
        ::StopSound(*this);
    }

    bool Sound::IsPlaying()
    {
        return (::IsSoundPlaying(*this));
    }

    void Sound::SetVolume(float volume)
    {
        ::SetSoundVolume(*this, volume);
    }

    void Sound::SetPitch(float pitch)
    {
        ::SetSoundPitch(*this, pitch);
    }
} // namespace raylib
