/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#include "core.hpp"
#include "../ECS/Systems/SystemRender.hpp"
#include "../../build/_deps/raylib-src/src/raylib.h"
#include "raylib/include/Window.hpp"

double clockToMilliseconds(clock_t ticks)
{
    return (ticks / ((double)CLOCKS_PER_SEC)) * ML_BASE;
}

int coreLoop()
{
    // clock_t sec_clock = clock();
    // clock_t fps_clock = clock();
    // int running = 1;
    // int fps = 0;
    // int avg_fps = FPS_CAP;
    //--------------------------------------------
    // InitWindow(800, 600, "test print rectangle");

    std::string test = "test print model";
    raylib::Window window(800, 600, test);

    Camera camera;
    camera.position = { 10.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    // Camera camera;
    // camera.position = { 20.0f, 20.0f, 20.0f }; // Camera position
    // camera.target = { 0.0f, 8.0f, 0.0f };      // Camera looking at point
    // camera.up = { 0.0f, 1.6f, 0.0f };          // Camera up vector (rotation towards target)
    // camera.fovy = 45.0f;                                // Camera field-of-view Y
    // camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type
    Model tower = LoadModel("/home/nleclaire/Tek2_Epitech/Indie_Studio/B-YEP-400-NAN-4-1-indiestudio-matthis.lesur/assets/BOT.obj");
    BoundingBox box = GetModelBoundingBox(tower);
    // Texture2D txtr = LoadTexture("/home/nleclaire/Tek2_Epitech/Indie_Studio/B-YEP-400-NAN-4-1-indiestudio-matthis.lesur/assets/bombIndieStudio.jpg");
    // test.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = txtr;
    // Texture2D texture = LoadTexture("/home/nleclaire/Tek2_Epitech/Indie_Studio/B-YEP-400-NAN-4-1-indiestudio-matthis.lesur/assets/Orange_Base_Color.png");
    // tower.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    Vector3 towerPos = { 0.0f, 10.0f, 0.0f };
    // SystemRender test_draw_rect;
    SetCameraMode(camera, CAMERA_ORBITAL);
    SetTargetFPS(60);
    // //--------------------------------------------
    while (!WindowShouldClose()) {
        // if (clockToMilliseconds(clock() - fps_clock) >= FPS_CAP_REAL) {
        //     fps_clock = clock();
        //     fps++;

        //     // do tick-based actions here, eg: graphical rendering and stuff like that, I/O checking;
        // }

        // if (clockToMilliseconds(clock() - sec_clock) >= ML_BASE) {
        //     sec_clock = clock();
        //     avg_fps = (avg_fps + fps) / 2;
        //     // do game logic and stuff like that here, eg: this action happens every X seconds, not X fps...;
        //     printf("second tick, delta fps: %d, avg fps: %d fps is capped around: %d\n", fps, avg_fps, FPS_CAP);
        //     fps = 0;
        // }
        UpdateCamera(&camera);
        // test_draw_rect.update();
        BeginDrawing();
            ClearBackground(WHITE);
            BeginMode3D(camera);
                DrawModel(tower, towerPos, 1.0f, WHITE);
                // DrawModel(test, {0, 0, 0}, 1.0f, WHITE);
                DrawBoundingBox(box, GREEN);
                DrawCube(box.min, 1, 1, 1, RED);
                DrawCube(box.max, 1, 1, 1, RED);
                DrawGrid(10, 10.0f);
            EndMode3D();
        EndDrawing();
    }

    return (0);
}