/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** settingsMenu
*/

#include "settingsMenu.hpp"
#include "core/core.hpp"

static int checkClick()
{
    raylib::Mouse mouseIndex;
    if ((mouseIndex.GetX() >= 20) && (mouseIndex.GetY() >= 20) && (mouseIndex.GetX() < 51 + 20) && (mouseIndex.GetY() < 51 + 20)) {
        if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
            return (0);
    }
    return (1);
}

int settingMenu()
{
    raylib::Window Window;
    raylib::Font font;
    raylib::Texture bg;
    raylib::Texture goBack;
    raylib::Vector2 bgPos = {0.0, 0.0};
    raylib::Vector2 goBackPos = {20.0, 20.0};
    raylib::Vector2 textPos = {300.0, 100.0};
    int click = 1;

    Window.Init();
    bg.Load("assets/placeholder.png");
    goBack.Load("assets/goBack.png");
    while (1) {
        if (Window.ShouldClose())
            break;
        Window.BeginDrawing();
        ClearBackground(raylib::Color::White());
        bg.Draw(bgPos, raylib::Color::White());
        goBack.Draw(goBackPos, 0, 0.1, raylib::Color::White());
        font.DrawText("Params Screen", textPos, 40, 2, raylib::Color::Black());
        click = checkClick();
        Window.EndDrawing();
        if (click != 1)
            return (click);
    }
    return (-1);
}