/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** winMenu
*/

#include "winMenu.hpp"
#include "ECS/ecs.hpp"

static ecs::IEntity *createButton(ecs::Core &menu, raylib::Vector2 posButton, std::string textButton)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentButton>(posButton, textButton);
    buttonEntity->add<ComponentClickable>();
    buttonEntity->get<ComponentButton>()->setIdButton(menu.getNbButtons());
    menu.increaseNbButtons(1);
    return (buttonEntity);
}

static ecs::Core initWinMenu(std::string winner)
{
    ecs::Core menu;
    ecs::IEntity *player = new ecs::IEntity();
    player->add<ComponentDrawable>(false, true);
    player->add<ComponentModel>("assets/models3D/Among_Us_red.obj", raylib::Vector3(0.0f, -1.0f, 0.5f), raylib::Vector3(0.7f, 0.7f, 0.7f));
    player->add<ComponentTexture>("assets/connectPlayers/AmongUsTrsp.png", raylib::Vector2(790.0f, 330.0f), raylib::Vector2(255.0f, 820.0f));
    player->add<ComponentControllable>();
    ecs::IEntity *buttonSave = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 860.0), "Return Main Menu");
    ecs::IEntity *background = new ecs::IEntity();
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTexture>("assets/connectPlayers/bgConnectPlayers.png", raylib::Vector2(0.0f, 0.0f));
    ecs::IEntity *scanner = new ecs::IEntity();
    scanner->add<ComponentDrawable>(true, false);
    scanner->add<ComponentTexture>("assets/connectPlayers/scanner.png", raylib::Vector2(760.0f, 580.0f));

    ecs::IEntity *textConnection = new ecs::IEntity();
    textConnection->add<ComponentDrawable>(true, false);
    textConnection->add<ComponentText>("assets/NewAthletic.ttf", winner + " Win", raylib::Vector2(740.0f, 200.0f), 90, raylib::Color::White());
    menu.setScene(ecs::Scenes::Win);

    menu.add<ecs::SystemRender2D>();
    menu.add<ecs::SystemRender3D>();
    menu.add<ecs::SystemEvent>();
    menu.addEntity(background);
    menu.addEntity(textConnection);
    menu.addEntity(buttonSave);
    menu.addEntity(scanner);
    menu.addEntity(player);
    return (menu);
}

ecs::Scenes winMenu(std::string winner)
{
    ecs::Core menu = initWinMenu(winner);
    raylib::Camera3D camera(raylib::Vector3(0.0f, 3.0f, 10.0f), raylib::Vector3(0.0f, 0.0f, 0.0f), raylib::Vector3(0.0f, 1.0f, 0.0f), 45.0f);

    while (menu.getScene() == ecs::Scenes::Win) {
        raylib::Window::BeginDrawing();
        raylib::Window::Clear(raylib::Color::White());
        menu.get<ecs::SystemEvent>()->update(menu);
        menu.get<ecs::SystemRender2D>()->update(menu);
        camera.BeginMode();
        menu.get<ecs::SystemRender3D>()->update(menu);
        camera.EndMode();
        raylib::Window::EndDrawing();
    }
    return (menu.getScene());
}
