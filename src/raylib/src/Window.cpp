/*
** EPITECH PROJECT, 2022
** Window
** File description:
** Window
*/

#include "../include/Window.hpp"
#include "../include/RaylibException.hpp"

void raylib::Window::Close()
{
    ::CloseWindow();
}

void raylib::Window::Init(int width, int height, const std::string &title)
{
    ::InitWindow(width, height, title.c_str());
    if (!isReady())
        throw RaylibException("Failed to create window");
}

bool raylib::Window::isReady()
{
    return (::IsWindowReady());
}

bool raylib::Window::ShouldClose()
{
    return (::WindowShouldClose());
}

bool raylib::Window::IsFullscreen()
{
    return (::IsWindowFullscreen());
}

bool raylib::Window::IsMinimized()
{
    return (::IsWindowMinimized());
}

bool raylib::Window::IsMaximized()
{
    return (::IsWindowMaximized());
}

bool raylib::Window::IsResized()
{
    return (::IsWindowResized());
}

void raylib::Window::Maximize()
{
    ::MaximizeWindow();
}

void raylib::Window::Minimize()
{
    ::MaximizeWindow();
}

void raylib::Window::Restore()
{
    ::RestoreWindow();
}

void raylib::Window::SetIcon(::Image &image)
{
    ::SetWindowIcon(image);
}

void raylib::Window::SetTitle(const std::string &title)
{
    ::SetWindowTitle(title.c_str());
}

void raylib::Window::SetPosition(int x, int y)
{
    ::SetWindowPosition(x, y);
}

void raylib::Window::SetMinSize(int width, int height)
{
    ::SetWindowMinSize(width, height);
}

void raylib::Window::SetSize(int width, int height)
{
    ::SetWindowSize(width, height);
}

int raylib::Window::GetWidth()
{
    return (::GetScreenWidth());
}

int raylib::Window::GetHeight()
{
    return (::GetScreenHeight());
}

::Vector2 raylib::Window::GetPosition()
{
    return (::GetWindowPosition());
}

void raylib::Window::BeginDrawing()
{
    ::BeginDrawing();
}

void raylib::Window::EndDrawing()
{
    ::EndDrawing();
}

float raylib::Window::GetFrameTime()
{
    return (::GetFrameTime());
}

double raylib::Window::GetTime()
{
    return (::GetTime());
}

void raylib::Window::Clear(Color color)
{
    ::ClearBackground(color);
}

void raylib::Window::SetFullScreen()
{
    ::SetWindowState(FLAG_FULLSCREEN_MODE);
}

void raylib::Window::ClearFullScreen()
{
    ::ClearWindowState(FLAG_FULLSCREEN_MODE);
}

void raylib::Window::InitAudioDevice()
{
    ::InitAudioDevice();
}

void raylib::Window::CloseAudioDevice()
{
    ::CloseAudioDevice();
}

bool raylib::Window::IsAudioDeviceReady()
{
    return (::IsAudioDeviceReady());
}

void raylib::Window::SetMasterVolume(float volume)
{
    ::SetMasterVolume(volume);
}

void raylib::Window::StopSounds()
{
    ::StopSoundMulti();
}

raylib::Vector2 raylib::Window::GetWorldToScreen(::Vector3 pos, raylib::Camera3D cam)
{
    raylib::Vector2 vec(::GetWorldToScreen(pos, cam));
    return (vec);
}
