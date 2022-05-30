/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** main
*/

#include "core/core.hpp"
#include "core/mainMenu.hpp"
#include "core/settingsMenu.hpp"

int mainLoop()
{
    int res = 0;
    
    while (res != -1) {
        switch (res)
        {
        case 0:
            res = mainMenu();
            break;
        case 1:
            res = coreLoop();
            break;
        case 2:
            // res = reload();
            break;
        case 3:
            res = settingMenu();
            break;
        case -1:
            return (-1);
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    mainLoop();
    return 0;
}