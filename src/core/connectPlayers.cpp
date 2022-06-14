/*
** EPITECH PROJECT, 2022
** connectPlayers
** File description:
** connectPlayers
*/

#include "connectPlayers.hpp"

static ecs::Core initConnectPlayers()
{
    ecs::Core connect;
    ecs::IEntity *player = new ecs::IEntity();
    player->add<ComponentDrawable>(false, true);
    player->add<ComponentModel>("models3D/AmongUsred.obj", raylib::Vector3(0.0f, 0.0f, 0.0f));
    ecs::IEntity *player2 = new ecs::IEntity();
    player2->add<ComponentDrawable>(false, true);
    player2->add<ComponentModel>("models3D/AmongUsblue.obj", raylib::Vector3(2.0f, 0.0f, 0.0f));
    ecs::IEntity *player3 = new ecs::IEntity();
    player3->add<ComponentDrawable>(false, true);
    player3->add<ComponentModel>("models3D/AmongUswhite.obj", raylib::Vector3(4.0f, 0.0f, 0.0f));
    ecs::IEntity *player4 = new ecs::IEntity();
    player4->add<ComponentDrawable>(false, true);
    player4->add<ComponentModel>("models3D/AmongUsblack.obj", raylib::Vector3(6.0f, 0.0f, 0.0f));
    connect.setScene(ecs::Scenes::ConnectPlayers);

    connect.add<ecs::SystemRender3D>();
    connect.add<ecs::SystemEvent>();
    connect.addEntity(player);
    connect.addEntity(player2);
    connect.addEntity(player3);
    connect.addEntity(player4);
    return (connect);
}

ecs::Scenes connectPlayers()
{
    raylib::Window::Init();
    ecs::Core connect = initConnectPlayers();
    raylib::Camera3D camera(raylib::Vector3(0.0f, 10.0f, 10.0f),
    raylib::Vector3(0.0f, 0.0f, 0.0f),
    raylib::Vector3(0.0f, 1.0f, 0.0f), 45.0f);

    while (!raylib::Window::ShouldClose() && connect.getScene() == ecs::Scenes::ConnectPlayers) {
        raylib::Window::BeginDrawing();
        raylib::Window::Clear(raylib::Color::White());
        connect.get<ecs::SystemEvent>()->update(connect);
        camera.BeginMode();
        connect.get<ecs::SystemRender3D>()->update(connect);
        DrawGrid(10, 1.0);
        camera.EndMode();
        raylib::Window::EndDrawing();
    }
    raylib::Window::Close();
    connect.setScene(ecs::Scenes::Close);
    return (connect.getScene());
}
