/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** mainMenu
*/

#include "mainMenu.hpp"

static int checkClick()
{
    raylib::Mouse mouseIndex;
    if ((mouseIndex.GetX() >= 300) && (mouseIndex.GetY() >= 100) && (mouseIndex.GetX() < 300 + 200) && (mouseIndex.GetY() < 100 + 75)) {
        if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
            return (1);
    } else if ((mouseIndex.GetX() >= 300) && (mouseIndex.GetY() >= 250) && (mouseIndex.GetX() < 300 + 200) && (mouseIndex.GetY() < 250 + 75)) {
        if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
            return (2);
    } else if ((mouseIndex.GetX() >= 300) && (mouseIndex.GetY() >= 400) && (mouseIndex.GetX() < 300 + 200) && (mouseIndex.GetY() < 400 + 75)) {
        if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
            return (3);
    }
    return (0);
}

int mainMenu()
{
    return (1);
}