/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initMap
*/

#include "initMap.hpp"
#include "ECS/ecs.hpp"
#include "raylib/include/Texture.hpp"

static ecs::IEntity *meshEntityCreation(raylib::Vector3 posMesh, raylib::Vector3 sizeMesh, raylib::Color color, raylib::Texture texture)
{
    ecs::IEntity *mesh = new ecs::IEntity();

    mesh->add<ComponentDrawable>(false, true);
    mesh->add<ComponentMesh>(posMesh, sizeMesh, color, texture);
    return (mesh);
}

double clockToMilliseconds2(clock_t ticks)
{
    return (ticks / ((double)CLOCKS_PER_SEC)) * ML_BASE;
}

ecs::Core mapCreation()
{
    raylib::Texture floorTex;
    raylib::Texture meshTex;
    raylib::Texture destructTex;
    raylib::Texture wallTex;
    raylib::Texture wallupTex;
    raylib::Texture blockTex;
    floorTex.Load("assets/FLOOR.png");
    wallTex.Load("assets/Among_Us_Space.png");
    meshTex.Load("assets/WALL.png");
    destructTex.Load("assets/destructible.png");
    wallupTex.Load("assets/WALL up.png");
    blockTex.Load("assets/MicrosoftTeams-image (1).png");
    Map *map = new Map;
    map->generateMap();
    ecs::Core mapCreation;

    raylib::Vector3 pos = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 size = {1.0f, 1.0f, 1.0f};

    ecs::IEntity *FloorGame;
    raylib::Vector3 posFloorGame = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 sizeFloorGame = {MAP_SIZE, 0.1f, MAP_SIZE};
    FloorGame = meshEntityCreation(posFloorGame, sizeFloorGame, raylib::Color::White(), floorTex);

    ecs::IEntity *Floor;
    raylib::Vector3 posFloor = {0.0f, -0.01f, 0.0f};
    raylib::Vector3 sizeFloor = {MAP_SIZE*3, 0.1f, MAP_SIZE*3};
    Floor = meshEntityCreation(posFloor, sizeFloor, raylib::Color::White(), wallTex);

    ecs::IEntity *Floor2;
    raylib::Vector3 posFloor2 = {0.0f, (MAP_SIZE*3)/2, (MAP_SIZE*3)/2};
    raylib::Vector3 sizeFloor2 = {MAP_SIZE*3, MAP_SIZE*3, 0.1f};
    Floor2 = meshEntityCreation(posFloor2, sizeFloor2, raylib::Color::White(), wallTex);

    ecs::IEntity *Floor3;
    raylib::Vector3 posFloor3 = {(-MAP_SIZE*3)/2, (MAP_SIZE*3)/2, 0.0f};
    raylib::Vector3 sizeFloor3 = {0.5f, MAP_SIZE*3, MAP_SIZE*3};
    Floor3 = meshEntityCreation(posFloor3, sizeFloor3, raylib::Color::White(), wallTex);

    ecs::IEntity *Floor4;
    raylib::Vector3 posFloor4 = {(MAP_SIZE*3)/2, (MAP_SIZE*3)/2, 0.0f};
    raylib::Vector3 sizeFloor4 = {0.5f, MAP_SIZE*3, MAP_SIZE*3};
    Floor4 = meshEntityCreation(posFloor4, sizeFloor4, raylib::Color::White(), wallTex);

    ecs::IEntity *mesh1;
    raylib::Vector3 posMesh = {0.0f, 0.5f, (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2};
    raylib::Vector3 sizeMesh = {MAP_SIZE, 1.0f, 1.0f};
    mesh1 = meshEntityCreation(posMesh, sizeMesh, raylib::Color::White(), meshTex);

    ecs::IEntity *mesh2;
    raylib::Vector3 posMesh2 = {-8.0f, 0.5f, 0.5f};
    raylib::Vector3 sizeMesh2 = {1.0f, 1.0f, MAP_SIZE - 1};
    mesh2 = meshEntityCreation(posMesh2, sizeMesh2, raylib::Color::White(), wallupTex);

    ecs::IEntity *bis;
    raylib::Vector3 posbis = {-8.00f, 0.5f, 0.5f};
    raylib::Vector3 sizebis = {1.01f, 1.0f, MAP_SIZE - 1};
    bis = meshEntityCreation(posbis, sizebis, raylib::Color::White(), meshTex);

    ecs::IEntity *mesh3;
    raylib::Vector3 posMesh3 = {8.0f, 0.5f, 0.5f};
    raylib::Vector3 sizeMesh3 = {1.0f, 1.0f, MAP_SIZE - 1};
    mesh3 = meshEntityCreation(posMesh3, sizeMesh3, raylib::Color::White(), wallupTex);

    ecs::IEntity *bis2;
    raylib::Vector3 posbis2 = {8.00f, 0.5f, 0.5f};
    raylib::Vector3 sizebis2 = {1.01f, 1.0f, MAP_SIZE - 1};
    bis2 = meshEntityCreation(posbis2, sizebis2, raylib::Color::White(), meshTex);

    ecs::IEntity *mesh4;
    raylib::Vector3 posMesh4 = {0.0f, 0.5f, 8.0f};
    raylib::Vector3 sizeMesh4 = {MAP_SIZE - 2, 1.0f, 1.0f};
    mesh4 = meshEntityCreation(posMesh4, sizeMesh4, raylib::Color::White(), meshTex);

    mapCreation.add<ecs::SystemRender3D>();
    mapCreation.addEntity(mesh1);
    mapCreation.addEntity(bis);
    mapCreation.addEntity(bis2);
    mapCreation.addEntity(mesh2);
    mapCreation.addEntity(mesh3);
    mapCreation.addEntity(mesh4);
    mapCreation.addEntity(FloorGame);
    mapCreation.addEntity(Floor);
    mapCreation.addEntity(Floor2);
    mapCreation.addEntity(Floor3);
    mapCreation.addEntity(Floor4);

    raylib::Vector3 sizeCube = {1.0f, 1.0f, 1.0f};
    Vector3 initial = {-8.0f, 0.5f, -1.0f * (MAP_SIZE / 2) + 1};
    for (int j = 1; j < MAP_SIZE - 1; j++) {
        for (int i = 1; i < MAP_SIZE - 1; i++) {
            initial.x += 1;
            if (map->getMap()[i][j] == 2) {
                ecs::IEntity *cube = new ecs::IEntity();
                cube->add<ComponentDrawable>(false, true);
                cube->add<ComponentCube>(initial, sizeCube, raylib::Color::White(), destructTex);
                mapCreation.addEntity(cube);
            } else if (map->getMap()[i][j] == 1) {
                ecs::IEntity *cube = new ecs::IEntity();
                cube->add<ComponentDrawable>(false, true);
                cube->add<ComponentCube>(initial, sizeCube, raylib::Color::White(), blockTex);
                mapCreation.addEntity(cube);
            }
        }
        initial.x = (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2;
        initial.z += 1.0f;
    }
    // meshTex.Unload();
    // destructTex.Unload();
    // floorTex.Unload();

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
