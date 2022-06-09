/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** main
*/

#include "core/core.hpp"
#include "core/mainMenu.hpp"
#include "core/settingsMenu.hpp"

int mainLoop(ecs::Core index)
{
    int res = 4;

    switch (res) {
        case 0: res = mainMenu(); break;
        case 1: res = coreLoop(index); break;
        case 2:
            // res = reload();
            break;
        case 3: res = settingMenu(); break;
        case 4:
            Map *map = new Map;

            map->generateMap();
            map->readMap();
            mapCreation(map);
            break;
    }
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    ecs::Core index = initEntities();
    mainLoop(index);
    return 0;
}
