/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initMap
*/

#include "initMap.hpp"
#include "ECS/ecs.hpp"

static ecs::IEntity *meshEntityCreation(raylib::Vector3 posMesh, raylib::Vector3 sizeMesh, raylib::Color color)
{
    ecs::IEntity *mesh = new ecs::IEntity();

    mesh->add<ComponentDrawable>(false, true);
    mesh->add<ComponentMesh>(posMesh, sizeMesh, color);
    return (mesh);
}

double clockToMilliseconds2(clock_t ticks)
{
    return (ticks / ((double)CLOCKS_PER_SEC)) * ML_BASE;
}

ecs::Core mapCreation()
{
    raylib::Texture floorTex = raylib::Texture::Load("assets/Dirt Tex.png");
    raylib::Texture meshTex = raylib::Texture::Load("assets/CUBE WALL.png");
    raylib::Texture destructTex = raylib::Texture::Load("assets/MicrosoftTeams-image.png");
    Map *map = new Map;
    map->generateMap();
    ecs::Core mapCreation;

    raylib::Vector3 pos = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 size = {1.0f, 1.0f, 1.0f};

    ecs::IEntity *Floor;
    raylib::Vector3 posFloor = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 sizeFloor = {MAP_SIZE, 0.1f, MAP_SIZE};
    Floor = meshEntityCreation(posFloor, sizeFloor, raylib::Color::Red());

    ecs::IEntity *mesh1;
    raylib::Vector3 posMesh = {0.0f, 0.5f, (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2};
    raylib::Vector3 sizeMesh = {MAP_SIZE, 1.0f, 1.0f};
    mesh1 = meshEntityCreation(posMesh, sizeMesh, raylib::Color::Blue());

    ecs::IEntity *mesh2;
    raylib::Vector3 posMesh2 = {-8.0f, 0.5f, 0.5f};
    raylib::Vector3 sizeMesh2 = {1.0f, 1.0f, MAP_SIZE - 1};
    mesh2 = meshEntityCreation(posMesh2, sizeMesh2, raylib::Color::Blue());

    ecs::IEntity *mesh3;
    raylib::Vector3 posMesh3 = {8.0f, 0.5f, 0.5f};
    raylib::Vector3 sizeMesh3 = {1.0f, 1.0f, MAP_SIZE - 1};
    mesh3 = meshEntityCreation(posMesh3, sizeMesh3, raylib::Color::Blue());

    ecs::IEntity *mesh4;
    raylib::Vector3 posMesh4 = {0.0f, 0.5f, 8.0f};
    raylib::Vector3 sizeMesh4 = {MAP_SIZE - 2, 1.0f, 1.0f};
    mesh4 = meshEntityCreation(posMesh4, sizeMesh4, raylib::Color::Blue());

    mapCreation.add<ecs::SystemRender3D>();
    mapCreation.addEntity(mesh1);
    mapCreation.addEntity(mesh2);
    mapCreation.addEntity(mesh3);
    mapCreation.addEntity(mesh4);
    mapCreation.addEntity(Floor);

    raylib::Vector3 sizeCube = {1.0f, 1.0f, 1.0f};
    Vector3 initial = {-8.0f, 0.5f, -1.0f * (MAP_SIZE / 2) + 1};
    for (int j = 1; j < MAP_SIZE - 1; j++) {
        for (int i = 1; i < MAP_SIZE - 1; i++) {
            initial.x += 1;
            if (map->getMap()[i][j] == 2) {
                ecs::IEntity *cube = new ecs::IEntity();
                cube->add<ComponentDrawable>(false, true);
                cube->add<ComponentCube>(initial, sizeCube, raylib::Color::White(), meshTex);
                mapCreation.addEntity(cube);
            } else if (map->getMap()[i][j] == 1) {
                ecs::IEntity *cube = new ecs::IEntity();
                cube->add<ComponentDrawable>(false, true);
                cube->add<ComponentCube>(initial, sizeCube, raylib::Color::White(), destructTex);
                mapCreation.addEntity(cube);
            }
        }
        initial.x = (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2;
        initial.z += 1.0f;
    }
    raylib::Texture::Unload();

    // clock_t sec_clock = clock();
    // clock_t fps_clock = clock();
    // ecs::Core index;
    // int running = 1;
    // int fps = 0;
    // int avg_fps = FPS_CAP;
    // raylib::Camera3D camera;
    // raylib::Vector3 initialCamPos = {0.0f, 10.0f, 10.0f};
    // camera.position = initialCamPos;
    // raylib::Vector3 initialCamTarget = {0.0f, 0.0f, 0.0f};
    // camera.target = initialCamTarget;
    // raylib::Vector3 initialCamUp = {0.0f, 1.0f, 0.0f};
    // camera.up = initialCamUp;
    // camera.fovy = 80.0f;
    // camera.projection = CAMERA_PERSPECTIVE;
    // index = mapCreation;
    // while (running) {
    //     if (clockToMilliseconds2(clock() - fps_clock) >= FPS_CAP_REAL) {
    //         fps_clock = clock();
    //         fps++;

    //         raylib::Window::BeginDrawing();
    //         raylib::Window::Clear(raylib::Color::White());
    //         camera.BeginMode();
    //             index.get<ecs::SystemRender3D>()->update(index);
    //         camera.EndMode();
    //         raylib::Window::EndDrawing();
    //     }

    //     if (clockToMilliseconds2(clock() - sec_clock) >= ML_BASE) {
    //         sec_clock = clock();
    //         avg_fps = (avg_fps + fps) / 2;
    //         // do game logic and stuff like that here, eg: this action happens every X seconds, not X fps...;
    //         printf("second tick, delta fps: %d, avg fps: %d fps is capped around: %d\n", fps, avg_fps, FPS_CAP);
    //         fps = 0;
    //     }
    // }

    return (mapCreation);
}
