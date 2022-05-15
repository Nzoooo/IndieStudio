/*
** EPITECH PROJECT, 2022
** SystemRender
** File description:
** SystemRender
*/

#include "SystemRender.hpp"
#include "raylib.h"

void SystemRender::update()
{
    // while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(200, 200, 400, 200, RED); // or create a Rectangle rec = {x,y,width,height}, or Rectangle{x,y,width,height} directly in parameter
        DrawRectangleLines(200, 200, 400, 200, BLUE);
        EndDrawing();
    // }
}
