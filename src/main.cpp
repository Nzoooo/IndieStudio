/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** main
*/

#include "core/core.hpp"
#include "core/information/info.hpp"
#include "core/mainMenu.hpp"

int mainLoop(ecs::Core core)
{
    int res = 4;

    while (res != -1) {
        switch (core.getScene()) {
            case ecs::Scenes::Menu: core.setScene(mainMenu()); break;
            case ecs::Scenes::Game: res = coreLoop(core); break;
            case ecs::Scenes::GameSettings:
                // res = reload();
                break;
            case ecs::Scenes::ConnectPlayers: break;
            case ecs::Scenes::Win: break;
            case ecs::Close: return (-1);
        }
    }
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
