/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#include "core.hpp"
#include "initMap.hpp"

double clockToMilliseconds(clock_t ticks)
{
    return (ticks / ((double)CLOCKS_PER_SEC)) * ML_BASE;
}

int coreLoop()
{
    clock_t sec_clock = clock();
    clock_t fps_clock = clock();
    ecs::Core index = mapCreation();
    int running = 1;
    int fps = 0;
    int avg_fps = FPS_CAP;
    raylib::Camera3D camera;
    raylib::Vector3 initialCamPos = {0.0f, 10.0f, 10.0f};
    camera.position = initialCamPos;
    raylib::Vector3 initialCamTarget = {0.0f, 0.0f, 0.0f};
    camera.target = initialCamTarget;
    raylib::Vector3 initialCamUp = {0.0f, 1.0f, 0.0f};
    camera.up = initialCamUp;
    camera.fovy = 80.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    bool isOrbital = true;
    bool step = false;
    bool first = true;
    float step1 = MAP_SIZE/2;

    camera.SetMode(CAMERA_ORBITAL);
    while (running) {
        if (clockToMilliseconds(clock() - fps_clock) >= FPS_CAP_REAL) {
            fps_clock = clock();
            fps++;

            camera.Update();

            if ((fps) == 1 && isOrbital == true) {
                camera.SetMode(CAMERA_CUSTOM);
                isOrbital = false;
            }
            if (camera.position.x <= step1 && step != true) {
                camera.position.x += 0.1f/2;
            } else {
                first = false;
            }
            if (isOrbital == false && camera.position.y < 12.5f
                && first != true) {
                camera.position.y += 0.09f/2;
                camera.position.z += 0.13f/2;
                camera.position.x = initialCamPos.x;
                step = true;
            }
            raylib::Window::BeginDrawing();
            raylib::Window::Clear(raylib::Color::White());
            camera.BeginMode();
            index.get<ecs::SystemRender3D>()->update(index);
            camera.EndMode();
            raylib::Window::EndDrawing();
        }

        if (clockToMilliseconds(clock() - sec_clock) >= ML_BASE) {
            sec_clock = clock();
            avg_fps = (avg_fps + fps) / 2;
            // do game logic and stuff like that here, eg: this action happens every X seconds, not X fps...;
            printf("second tick, delta fps: %d, avg fps: %d fps is capped around: %d\n", fps, avg_fps, FPS_CAP);
            fps = 0;
        }
    }
    return (0);
}
