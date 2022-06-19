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
    core.setStartMode(ecs::GameStartMode::NONE);
    std::string winner;

    while (1) {
        switch (core.getScene()) {
            case ecs::Scenes::Menu: core.setScene(mainMenu(core)); break;
            case ecs::Scenes::Game: try { core.setScene(coreLoop(idControllers, settings, winner, core.getStartMode()));
                } catch (...) {
                    std::cout << "Can't find the saved file." << std::endl;
                    core.setScene(ecs::Scenes::Menu);
                }
                break;
            case ecs::Scenes::GameSettings: core.setScene(gameSettings(settings, idControllers)); break;
            case ecs::Scenes::ConnectPlayers: core.setScene(connectPlayers(core, idControllers)); break;
            case ecs::Scenes::Win: core.setScene(winMenu(winner)); break;
            case ecs::Close: return (-1);
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
