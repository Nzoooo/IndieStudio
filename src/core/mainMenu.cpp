/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** mainMenu
*/

#include "mainMenu.hpp"
#include "raylib/include/Rectangle.hpp"
#include "raylib/include/Color.hpp"

void mainMenu()
{
    raylib::Window Window;
    raylib::Rectangle buttonStart(300.0, 100.0, 200.0, 75.0);
    raylib::Rectangle buttonReload(300.0, 250.0, 200.0, 75.0);
    raylib::Rectangle buttonParam(300.0, 400.0, 200.0, 75.0);
    raylib::Color colorButton(100, 100, 100, 255);

    while (1) {
        if (Window.ShouldClose())
            break;
        Window.BeginDrawing();
            ClearBackground(WHITE);
            buttonStart.DrawRounded(20.0, 20, colorButton);
            buttonReload.DrawRounded(20.0, 20, colorButton);
            buttonParam.DrawRounded(20.0, 20, colorButton);
        Window.EndDrawing();
    }
}