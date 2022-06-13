/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** main
*/

#include "ECS/Systems/SystemRender3D.hpp"
#include "core/core.hpp"
#include "core/initMap.hpp"
#include "core/mainMenu.hpp"
#include "map/Map.hpp"

int mainLoop(ecs::Core index)
{
    index.setScene(ecs::Scenes::Game);
    Map *map;

    while (index.getScene() != ecs::Scenes::Win) {
        switch (index.getScene()) {
            case ecs::Scenes::Game: mapCreation(map); break;
            case ecs::Scenes::Menu: index.setScene(mainMenu()); break;
            case ecs::Scenes::GameSettings:
                // res = reload();
                break;
            case -1: return (-1);
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    ecs::Core index = initEntities();
    ecs::SystemRender3D system;
    index.setScene(ecs::Scenes::Menu);
    mainLoop(index);
    return 0;
}
