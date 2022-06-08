/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** settingsMenu
*/

#include "settingsMenu.hpp"
#include "core/core.hpp"
#include "ECS/Systems/SystemEvent.hpp"
#include "../raylib/include/Gamepad.hpp"

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
    // ecs::Core index;
    // raylib::Window Window;
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - gamepad input");
    // Window.Init();
    // SystemEvent event;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // event.update(index);
        // for (int i = 0; i <= raylib::Gamepad::gamepadNumber; i++) {
            // if (raylib::Gamepad::IsAvailable(i)) {
        if (IsGamepadAvailable(0)) {
            DrawText(TextFormat("GP1: %s", GetGamepadName(0)), 10, 10, 10, BLACK);
            DrawText(TextFormat("DETECTED AXIS [%i]:", GetGamepadAxisCount(0)), 10, 50, 10, MAROON);
            for (int i = 0; i < GetGamepadAxisCount(0); i++)
            {
                DrawText(TextFormat("AXIS %i: %.02f", i, GetGamepadAxisMovement(0, i)), 20, 70 + 20*i, 10, DARKGRAY);
            }
            if (GetGamepadButtonPressed() != -1) DrawText(TextFormat("DETECTED BUTTON: %i", GetGamepadButtonPressed()), 10, 430, 10, RED);
            else DrawText("DETECTED BUTTON: NONE", 10, 430, 10, GRAY);
        } else {
            DrawText("GP1: NOT DETECTED", 10, 10, 10, GRAY);
        }
            // }
        // }
        EndDrawing();
    }
    CloseWindow();
    // raylib::Window Window;
    // raylib::Font font;
    // raylib::Texture bg;
    // raylib::Texture goBack;
    // raylib::Vector2 bgPos = {0.0, 0.0};
    // raylib::Vector2 goBackPos = {20.0, 20.0};
    // raylib::Vector2 textPos = {300.0, 100.0};
    // int click = 1;

    // Window.Init();
    // bg.Load("assets/placeholder.png");
    // goBack.Load("assets/goBack.png");
    // while (1) {
    //     if (Window.ShouldClose())
    //         break;
    //     Window.BeginDrawing();
    //     ClearBackground(raylib::Color::White());
    //     bg.Draw(bgPos, raylib::Color::White());
    //     goBack.Draw(goBackPos, 0, 0.1, raylib::Color::White());
    //     font.DrawText("Params Screen", textPos, 40, 2, raylib::Color::Black());
    //     click = checkClick();
    //     Window.EndDrawing();
    //     if (click != 1)
    //         return (click);
    // }
    return (-1);
}