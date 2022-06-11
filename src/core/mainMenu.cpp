/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** mainMenu
*/

#include "../ECS/ecs.hpp"
#include "mainMenu.hpp"

static ecs::IEntity *createButton(ecs::Core menu, raylib::Vector2 posButton, std::string textButton)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentButton>(posButton, textButton);
    buttonEntity->add<ComponentClickable>();
    buttonEntity->get<ComponentButton>()->setIdButton(menu.getNbButtons());
    menu.increaseNbButtons(1);
    return (buttonEntity);
}

static ecs::Core initMenu()
{
    ecs::Core menu;
    ecs::IEntity *buttonStart = createButton(menu, raylib::Vector2(800 / 2.0f - 358 / 2.0f, 150.0), "Start Game");
    buttonStart->get<ComponentButton>()->setState(true);
    ecs::IEntity *buttonReload = createButton(menu, raylib::Vector2(800 / 2.0f - 358 / 2.0f, 300.0), "Reload Game");
    ecs::IEntity *buttonParam = createButton(menu, raylib::Vector2(800 / 2.0f - 358 / 2.0f, 450.0), "Settings");
    ecs::IEntity *backgroung = new ecs::IEntity();
    ecs::IEntity *logo = new ecs::IEntity();
    backgroung->add<ComponentDrawable>(true, false);
    backgroung->add<ComponentTexture>("../assets/background.png", raylib::Vector2(0, 0));
    logo->add<ComponentDrawable>(true, false);
    logo->add<ComponentTexture>("../assets/Logo.png", raylib::Vector2(800 / 2.0f - 200 / 2.0f, 30));
    menu.setScene(ecs::Scenes::Menu);

    menu.add<ecs::SystemRender2D>();
    menu.add<ecs::SystemEvent>();
    menu.addEntity(backgroung);
    menu.addEntity(logo);
    menu.addEntity(buttonStart);
    menu.addEntity(buttonReload);
    menu.addEntity(buttonParam);
    menu.increaseNbButtons(3);
    return (menu);
}

ecs::Scenes mainMenu()
{
    raylib::Window::Init();
    ecs::Core menu = initMenu();

    raylib::Window::SetFullScreen();
    while (!raylib::Window::ShouldClose() && menu.getScene() == ecs::Scenes::Menu) {
        raylib::Window::Clear(raylib::Color::White());
        raylib::Window::BeginDrawing();
          menu.get<ecs::SystemEvent>()->update(menu);
          menu.get<ecs::SystemRender2D>()->update(menu);
        raylib::Window::EndDrawing();
    }
    raylib::Window::Close();
    return (menu.getScene());
}
