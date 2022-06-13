/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initMap
*/

#include "ECS/Components/ComponentCube.hpp"
#include "ECS/Components/ComponentDrawable.hpp"
#include "core/core.hpp"
#include "core/mainMenu.hpp"
#include "core/settingsMenu.hpp"

static ecs::IEntity *createCube(raylib::Vector3 pos, raylib::Vector3 size)
{
    ecs::IEntity *entity = new ecs::IEntity();

    entity->add<ComponentDrawable>(true, false);
    entity->add<ComponentCube>(pos, size);
    return (entity);
}

void mapCreation(Map *map)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Camera3D camera = {};
    Vector3 initialCamPos = {0.0f, 10.0f, 10.0f};
    camera.position = initialCamPos;
    Vector3 initialCamTarget = {0.0f, 0.0f, 0.0f};
    camera.target = initialCamTarget;
    Vector3 initialCamUp = {0.0f, 1.0f, 0.0f};
    camera.up = initialCamUp;
    camera.fovy = 80.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    int i = 0;

    raylib::Vector3 initialFloorPos = {0.0f, -0.05f, 0.0f};
    Vector3 initial = {0.0f, 0.5f, (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2};
    Model models[4] = { 0 };

    Vector3 initialPos[4] = {};

    initialPos[0] = {0.0f, 0.5f, (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2};
    initialPos[1] = {-8.0f, 0.5f, 0.5f};
    initialPos[2] = {8.0f, 0.5f, 0.5f};
    initialPos[3] = {0.0f, 0.5f, 8.0f};

    models[0] = LoadModelFromMesh(GenMeshCube(MAP_SIZE, 1.0f, 1.0f));
    models[1] = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, MAP_SIZE - 1));
    models[2] = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, MAP_SIZE - 1));
    models[3] = LoadModelFromMesh(GenMeshCube(MAP_SIZE - 2, 1.0f, 1.0f));
    std::vector<ecs::IEntity *> cubes;
    for (int j = 0; j < MAP_SIZE; j++) {
        for (i = 0; i < MAP_SIZE; i++) {
            cubes.push_back(createCube(initial, {1.0f, 1.0f, 1.0f}));
            initial.x += 1;
        }
        initial.x = (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2;
        initial.z += 1.0f;
    }
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        initialFloorPos.DrawCube(1.0f * MAP_SIZE, 0.1f, 1.0f * MAP_SIZE, RED);
        initialFloorPos.DrawCubeWires(1.0f * MAP_SIZE, 0.1f, 1.0f * MAP_SIZE, BLACK);
        for (size_t i = 0; i < 4; i++)
        {
            DrawModel(models[i], initialPos[i], 1.0f, BLACK);
        }
        
        for (i = 1; i < MAP_SIZE - 1; i++) {
            for (size_t j = 1; j < MAP_SIZE - 1; j++) {
                if (map->getMap()[i][j] == WALL) {
                    cubes[i * MAP_SIZE + j]->get<ComponentCube>()->setColor(raylib::Color::Green());
                    DrawCube(cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getPos(), cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getSize().x,
                        cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getSize().y, cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getSize().z,
                        cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getColor());
                } else if (map->getMap()[i][j] == BOX) {
                    cubes[i * MAP_SIZE + j]->get<ComponentCube>()->setColor(raylib::Color::Blue());
                    DrawCube(cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getPos(), cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getSize().x,
                        cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getSize().y, cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getSize().z,
                        cubes[i * MAP_SIZE + j]->get<ComponentCube>()->getColor());
                }
            }
        }
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
}
