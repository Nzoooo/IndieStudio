/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** main
*/

#include "core/connectPlayers.hpp"
#include "core/core.hpp"
#include "core/gameSettings.hpp"
#include "core/information/info.hpp"
#include "core/mainMenu.hpp"
#include "core/winMenu.hpp"
#include "map/Map.hpp"

static int mainLoop()
{
    raylib::Window::Init(1920, 1080);
    raylib::Window::InitAudioDevice();
    raylib::Window::SetFullScreen();
    ecs::Core core;
    std::vector<int> idControllers;
    std::vector<int> settings;
    settings.reserve(3);
    core.setScene(ecs::Scenes::Menu);
    std::string winner;

    while (1) {
        switch (core.getScene()) {
            case ecs::Scenes::Menu: core.setScene(mainMenu()); break;
            case ecs::Scenes::Game: core.setScene(coreLoop(idControllers, settings, winner)); break;
            case ecs::Scenes::GameSettings: core.setScene(gameSettings(settings)); break;
            case ecs::Scenes::ConnectPlayers: core.setScene(connectPlayers(idControllers)); break;
            case ecs::Scenes::Win: core.setScene(winMenu(winner)); break;
            case ecs::Close: break;
        }
    }
    raylib::Window::StopSounds();
    raylib::Window::CloseAudioDevice();
    raylib::Window::Close();
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    mainLoop();
    return 0;
}
