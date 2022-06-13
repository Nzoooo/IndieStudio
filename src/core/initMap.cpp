/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initMap
*/

#include "initMap.hpp"
#include "ECS/ecs.hpp"


void meshEntityCreation(ecs::IEntity *mesh, raylib::Vector3 posMesh, raylib::Vector3 sizeMesh)
{
    mesh->add<ComponentDrawable>(false, true);
    mesh->add<ComponentMesh>(posMesh, sizeMesh, raylib::Color::Blue());
}

int mapCreation(Map *map)
{
    map->generateMap();
    map->readMap();
    ecs::Core mapCreation;
    raylib::Window::Init();

    raylib::Vector3 pos = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 size = {1.0f, 1.0f, 1.0f};

    ecs::IEntity *mesh1 = new ecs::IEntity();
    raylib::Vector3 posMesh = {0.0f, 0.5f, (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2};
    raylib::Vector3 sizeMesh = {MAP_SIZE, 1.0f, 1.0f};
    meshEntityCreation(mesh1, posMesh, sizeMesh);
    

    ecs::IEntity *mesh2 = new ecs::IEntity();
    raylib::Vector3 posMesh2 = {-8.0f, 0.5f, 0.5f};
    raylib::Vector3 sizeMesh2 = {1.0f, 1.0f, MAP_SIZE - 1};
    meshEntityCreation(mesh2, posMesh2, sizeMesh2);

    ecs::IEntity *mesh3 = new ecs::IEntity();
    raylib::Vector3 posMesh3 = {8.0f, 0.5f, 0.5f};
    raylib::Vector3 sizeMesh3 = {1.0f, 1.0f, MAP_SIZE - 1};
    meshEntityCreation(mesh3, posMesh3, sizeMesh3);

    ecs::IEntity *mesh4 = new ecs::IEntity();
    raylib::Vector3 posMesh4 = {0.0f, 0.5f, 8.0f};
    raylib::Vector3 sizeMesh4 = {MAP_SIZE - 2, 1.0f, 1.0f};
    meshEntityCreation(mesh4, posMesh4, sizeMesh4);

    mapCreation.add<ecs::SystemRender3D>();

    raylib::Vector3 sizeCube = {1.0f, 1.0f, 1.0f};
    Vector3 initial = {-8.0f, 0.5f, -1.0f * (MAP_SIZE / 2) + 1};
    for (int j = 1; j < MAP_SIZE - 1; j++) {
        for (int i = 1; i < MAP_SIZE - 1; i++) {
            initial.x += 1;
            if (map->getMap()[i][j] == 2) {
                ecs::IEntity *cube = new ecs::IEntity();
                cube->add<ComponentDrawable>(false, true);
                cube->add<ComponentCube>(initial, sizeCube, raylib::Color::Green());
                mapCreation.addEntity(cube);
            } else if (map->getMap()[i][j] == 1) {
                ecs::IEntity *cube = new ecs::IEntity();
                cube->add<ComponentDrawable>(false, true);
                cube->add<ComponentCube>(initial, sizeCube, raylib::Color::Blue());
                mapCreation.addEntity(cube);
            }
        }
        initial.x = (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2;
        initial.z += 1.0f;
    }

    mapCreation.addEntity(mesh1);
    mapCreation.addEntity(mesh2);
    mapCreation.addEntity(mesh3);
    mapCreation.addEntity(mesh4);
    Camera3D camera = {};
    Vector3 initialCamPos = {0.0f, 10.0f, 10.0f};
    camera.position = initialCamPos;
    Vector3 initialCamTarget = {0.0f, 0.0f, 0.0f};
    camera.target = initialCamTarget;
    Vector3 initialCamUp = {0.0f, 1.0f, 0.0f};
    camera.up = initialCamUp;
    camera.fovy = 80.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    while (!raylib::Window::ShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        mapCreation.get<ecs::SystemRender3D>()->update(mapCreation);
        DrawCubeWires(posMesh, MAP_SIZE, 1.0f, 1.0f, MAROON);
        DrawCubeWires(posMesh2, 1.0f, 1.0f, (MAP_SIZE - 1), MAROON);
        DrawCubeWires(posMesh3, 1.0f, 1.0f, (MAP_SIZE - 1), MAROON);
        DrawCubeWires(posMesh4, (MAP_SIZE - 2), 1.0f, 1.0f, MAROON);
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return (ecs::Scenes::Win);
}
