/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initMap
*/

#include "core/core.hpp"
#include "core/mainMenu.hpp"
#include "core/settingsMenu.hpp"

#define GAME_BOARD_SIZE 17

void mapCreation(Map *map)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    map->readMap();
    Camera3D camera = {};
    Vector3 initialCamPos = {0.0f, 10.0f, 10.0f};
    camera.position = initialCamPos; // Camera position
    Vector3 initialCamTarget = {0.0f, 0.0f, 0.0f};
    camera.target = initialCamTarget;
    Vector3 initialCamUp = {0.0f, 1.0f, 0.0f}; // Camera looking at point
    camera.up = initialCamUp;                  // Camera up vector (rotation towards target)
    camera.fovy = 80.0f;                      // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;
    int i = 0;
    int nbr = 0;

    Vector3 initialFloorPos = {0.0f, -0.05f, 0.0f};

    Vector3 initialPos = {-8.0f, 0.5f, -8.0f};
    std::vector<Vector3> cubes;
    for (int j = 0; j < GAME_BOARD_SIZE; j++) {
        for (i = 0; i < GAME_BOARD_SIZE; i++) {
            cubes.push_back(initialPos);
            initialPos.x += 1;
        }
        if (i == GAME_BOARD_SIZE) {
            initialPos.x = -8.0f;
            initialPos.z += 1.0f;
        }
    }
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawCube(initialFloorPos, 17.0f, 0.1f, 17.0f, RED);
        DrawCubeWires(initialFloorPos, 17.0f, 0.1f, 17.0f, BLACK);
        for (size_t i = 0; i < MAPSIZE; i++) { 
            for (size_t j = 0; j < MAPSIZE; j++) {
                if (map->_map[i][j] == 1) {
                    DrawCube(cubes[i * MAPSIZE + j], 1.0f, 1.0f, 1.0f, GREEN);
                    DrawCubeWires(cubes[i * MAPSIZE + j], 1.0f, 1.0f, 1.0f, BLACK);
                } else if (map->_map[i][j] == 2) {
                    DrawCube(cubes[i * MAPSIZE + j], 1.0f, 1.0f, 1.0f, BLUE);
                    DrawCubeWires(cubes[i * MAPSIZE + j], 1.0f, 1.0f, 1.0f, BLACK);
                }
            }
        }
        EndMode3D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
}