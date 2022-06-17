/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** main
*/

#include "core/connectPlayers.hpp"
#include "core/core.hpp"
#include "core/information/info.hpp"
#include "core/mainMenu.hpp"
#include "map/Map.hpp"

static int mainLoop()
{
    raylib::Window::Init(1920, 1080);
    ecs::Core core;
    core.setScene(ecs::Scenes::Menu);

    while (core.getScene() != ecs::Scenes::Win) {
        switch (core.getScene()) {
            case ecs::Scenes::Menu: core.setScene(mainMenu()); break;
            case ecs::Scenes::Game: core.setScene(coreLoop()); break;
            case ecs::Scenes::GameSettings: break;
            case ecs::Scenes::ConnectPlayers: break;
            case ecs::Scenes::Win: break;
            case ecs::Close: return (-1);
        }
    }
    CloseWindow();
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    mainLoop();
    return 0;
}
