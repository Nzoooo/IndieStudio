/*
** EPITECH PROJECT, 2022
** Music
** File description:
** Music
*/

#include "../include/Music.hpp"

namespace raylib
{
    Music::Music(const std::string &fileName)
    {
        Load(fileName);
    }

    Music::~Music()
    {
        Unload();
    }

    void Music::Load(const std::string &fileName)
    {
        ::Music music = LoadMusicStream(fileName.c_str());

        this->ctxData = music.ctxData;
        this->ctxType = music.ctxType;
        this->frameCount = music.frameCount;
        this->looping = music.looping;
        this->stream = music.stream;
    }

    void Music::Unload()
    {
        ::UnloadMusicStream(*this);
    }

    void Music::Play()
    {
        ::PlayMusicStream(*this);
    }

    void Music::Resume()
    {
        ::ResumeMusicStream(*this);
    }

    void Music::Pause()
    {
        ::PauseMusicStream(*this);
    }

    void Music::Stop()
    {
        ::StopMusicStream(*this);
    }

    bool Music::IsPlaying()
    {
        return (::IsMusicStreamPlaying(*this));
    }

    void Music::SetVolume(float volume)
    {
        ::SetMusicVolume(*this, volume);
    }

    void Music::SetPitch(float pitch)
    {
        ::SetMusicPitch(*this, pitch);
    }

    void Music::SeekMusic(float position)
    {
        ::SeekMusicStream(*this, position);
    }

    float Music::GetTimeLength()
    {
        return (::GetMusicTimeLength(*this));
    }

    float Music::GetTimePlayed()
    {
        return (::GetMusicTimePlayed(*this));
    }

    void Music::Update()
    {
        ::UpdateMusicStream(*this);
    }

} // namespace raylib
