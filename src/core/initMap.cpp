/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initMap
*/

#include "initMap.hpp"
#include "ECS/ecs.hpp"
#include "raylib/include/Gamepad.hpp"

static ecs::IEntity *meshEntityCreation(raylib::Vector3 posMesh, raylib::Vector3 sizeMesh, raylib::Color color)
{
    ecs::IEntity *mesh = new ecs::IEntity();

    mesh->add<ComponentDrawable>(false, true);
    mesh->add<ComponentCollider>();
    mesh->add<ComponentMesh>(posMesh, sizeMesh, color);
    return (mesh);
}

ecs::Core mapCreation()
{
    Map *map = new Map;
    map->generateMap();
    ecs::Core mapCreation;
    mapCreation.setScene(ecs::Scenes::Game);

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

    mapCreation.add<ecs::SystemEvent>();
    ecs::IEntity *player = new ecs::IEntity();
    raylib::Vector3 posPlayer = {-6.5f, 0.5f, MAP_SIZE / 2 - 1};
    raylib::Vector3 sizePlayer = {0.5f, 0.5f, 0.5f};
    // raylib::Gamepad::IsButtonUp();
    player->add<ComponentDrawable>(false, true);
    player->add<ComponentControllable>();
    // player->add<ComponentTransform>(sizePlayer.x, sizePlayer.y, posPlayer.x, posPlayer.y);
    player->add<ComponentCube>(posPlayer, sizePlayer, raylib::Color::Black());
    player->add<ComponentCollider>();
    player->add<ComponentMovable>(0.0f);

    mapCreation.add<ecs::SystemRender3D>();
    // mapCreation.addEntity(mesh1);
    // mapCreation.addEntity(mesh2);
    // mapCreation.addEntity(mesh3);
    // mapCreation.addEntity(mesh4);
    mapCreation.addEntity(Floor);
    mapCreation.addEntity(player);

    raylib::Vector3 sizeCube = {1.0f, 1.0f, 1.0f};
    Vector3 initial = {-8.0f, 0.5f, -1.0f * (MAP_SIZE / 2) + 1};
    for (int j = 1; j < MAP_SIZE - 1; j++) {
        for (int i = 1; i < MAP_SIZE - 1; i++) {
            initial.x += 1;
            if (map->getMap()[i][j] == 2) {
                ecs::IEntity *cube = new ecs::IEntity();
                cube->add<ComponentDrawable>(false, true);
                cube->add<ComponentKillable>();
                cube->add<ComponentCollider>();
                cube->get<ComponentCollider>()->setCollision(raylib::BoundingBox(raylib::Vector3(initial.x - sizeCube.x / 2, initial.y - sizeCube.y / 2, initial.z - sizeCube.z / 2),
                    raylib::Vector3(initial.x + sizeCube.x / 2, initial.y + sizeCube.y / 2, initial.z + sizeCube.z / 2 + 0.1f)));
                cube->add<ComponentCube>(initial, sizeCube, raylib::Color::Green());
                mapCreation.addEntity(cube);
            } else if (map->getMap()[i][j] == 1) {
                ecs::IEntity *cube = new ecs::IEntity();
                cube->add<ComponentDrawable>(false, true);
                cube->add<ComponentCollider>();
                cube->get<ComponentCollider>()->setCollision(raylib::BoundingBox(raylib::Vector3(initial.x - sizeCube.x / 2, initial.y - sizeCube.y / 2, initial.z - sizeCube.z / 2),
                    raylib::Vector3(initial.x + sizeCube.x / 2, initial.y + sizeCube.y / 2, initial.z + sizeCube.z / 2 + 0.1f)));
                cube->add<ComponentCube>(initial, sizeCube, raylib::Color::Blue());
                mapCreation.addEntity(cube);
            }
        }
        initial.x = (-1.0f * (MAP_SIZE - MAP_SIZE % 2)) / 2;
        initial.z += 1.0f;
    }
    return (mapCreation);
}
