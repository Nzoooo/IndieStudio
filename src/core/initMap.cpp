/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initMap
*/

#include "initMap.hpp"
#include "ECS/ecs.hpp"

void mapCreation(Map *map)
{
    ecs::Core mapCreation;
    ecs::IEntity *cube = new ecs::IEntity();

    raylib::Vector3 pos = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 size = {1.0f, 1.0f, 1.0f};

    cube->add<ComponentDrawable>(false, true);
    cube->add<ComponentCube>(pos, size, raylib::Color::Black());
    mapCreation.add<ecs::SystemRender3D>();
    mapCreation.addEntity(cube);

    raylib::Window::Init();
    Camera3D camera = {};
    Vector3 initialCamPos = {0.0f, 10.0f, 10.0f};
    camera.position = initialCamPos;
    Vector3 initialCamTarget = {0.0f, 0.0f, 0.0f};
    camera.target = initialCamTarget;
    Vector3 initialCamUp = {0.0f, 1.0f, 0.0f};
    camera.up = initialCamUp;
    camera.fovy = 80.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // raylib::Vector3 initialFloorPos = {0.0f, -0.05f, 0.0f};
    // Vector3 initial = {0.0f, 0.5f, (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2};
    // Model models[4] = { 0 };

    // Vector3 initialPos[4] = {};

    // initialPos[0] = {0.0f, 0.5f, (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2};
    // initialPos[1] = {-8.0f, 0.5f, 0.5f};
    // initialPos[2] = {8.0f, 0.5f, 0.5f};
    // initialPos[3] = {0.0f, 0.5f, 8.0f};

    // models[0] = LoadModelFromMesh(GenMeshCube(MAP_SIZE, 1.0f, 1.0f));
    // models[1] = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, MAP_SIZE - 1));
    // models[2] = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, MAP_SIZE - 1));
    // models[3] = LoadModelFromMesh(GenMeshCube(MAP_SIZE - 2, 1.0f, 1.0f));
    // std::vector<ecs::IEntity *> cubes;
    // for (int j = 0; j < MAP_SIZE; j++) {
    //     for (i = 0; i < MAP_SIZE; i++) {
    //         cubes.push_back(createCube(initial, {1.0f, 1.0f, 1.0f}));
    //         initial.x += 1;
    //     }
    //     initial.x = (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2;
    //     initial.z += 1.0f;
    // }
    // SetTargetFPS(60);
    while (!raylib::Window::ShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        mapCreation.get<ecs::SystemRender3D>()->update(mapCreation);
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
}
