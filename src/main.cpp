/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** main
*/

#include "ECS/Systems/SystemRender3D.hpp"
#include "core/core.hpp"
#include "core/information/info.hpp"
#include "core/mainMenu.hpp"
#include "map/Map.hpp"

int mainLoop(ecs::Core core)
{
    raylib::Window::Init(1920, 1080);
    index.setScene(ecs::Scenes::Menu);

    while (index.getScene() != ecs::Scenes::Win) {
        switch (index.getScene()) {
            case ecs::Scenes::Menu: index.setScene(mainMenu()); break;
            case ecs::Scenes::Game: coreLoop(); break;
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
    ecs::Core core = initEntities();
    core.setScene(ecs::Scenes::Menu);
    mainLoop(core);
    return 0;
}
