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
    raylib::Window Window;
    raylib::Rectangle buttonStart(300.0, 100.0, 200.0, 75.0);
    raylib::Rectangle buttonReload(300.0, 250.0, 200.0, 75.0);
    raylib::Rectangle buttonParam(300.0, 400.0, 200.0, 75.0);
    raylib::Color colorButton(100, 100, 100, 255);
    raylib::Font font("../assets/NewAthletic.ttf");
    raylib::Texture bg;
    bg.Load("../assets/placeholder.png");
    int click = 0;

    while (1) {
        if (Window.ShouldClose())
            break;
        Window.BeginDrawing();
            ClearBackground(WHITE);
            bg.Draw((Vector2){0.0, 0.0}, WHITE);
            buttonStart.DrawRounded(20.0, 20, colorButton);
            font.DrawText("Start", 360, 125, 30, WHITE);
            buttonReload.DrawRounded(20.0, 20, colorButton);
            font.DrawText("Reload game", 330, 275, 25, WHITE);
            buttonParam.DrawRounded(20.0, 20, colorButton);
            font.DrawText("Settings", 340, 425, 30, WHITE);
            click = checkClick();
        Window.EndDrawing();
        if (click != 0)
                return (click);
    }
    return (-1);
}