/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** settingsMenu
*/

#include "settingsMenu.hpp"

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
    raylib::Font font("../assets/NewAthletic.ttf");
    raylib::Texture bg;
    raylib::Texture goBack;
    int click = 1;

    bg.Load("../assets/placeholder.png");
    goBack.Load("../assets/goBack.png");
    while (1) {
        if (Window.ShouldClose())
            break;
        Window.BeginDrawing();
            ClearBackground(WHITE);
            bg.Draw((Vector2){0.0, 0.0}, WHITE);
            goBack.Draw((Vector2){20.0, 20.0}, 0, 0.1, WHITE);
            font.DrawText("Params Screen", (Vector2){ 300.0, 100.0 }, 40, 2, BLACK);
            click = checkClick();
        Window.EndDrawing();
        if (click != 1)
            return (click);
    }
    return (-1);
}