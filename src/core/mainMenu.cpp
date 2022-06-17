/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** mainMenu
*/

#include "mainMenu.hpp"

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

static ecs::Core initMenu()
{
    ecs::Core menu;
    ecs::IEntity *buttonStart = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 450.0), "Start Game");
    buttonStart->get<ComponentButton>()->setState(true);
    ecs::IEntity *buttonReload = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 600.0), "Reload Game");
    ecs::IEntity *buttonParam = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 750.0), "Exit");
    ecs::IEntity *background = new ecs::IEntity();
    ecs::IEntity *logo = new ecs::IEntity();
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTexture>("assets/background.png", raylib::Vector2(0, 0));
    logo->add<ComponentDrawable>(true, false);
    logo->add<ComponentTexture>("assets/Bomberman_Logo.png", raylib::Vector2(1920 / 2.0f - 500 / 2.0f, 150));
    menu.setScene(ecs::Scenes::Menu);

    menu.add<ecs::SystemRender2D>();
    menu.add<ecs::SystemEvent>();
    menu.addEntity(background);
    menu.addEntity(logo);
    menu.addEntity(buttonStart);
    menu.addEntity(buttonReload);
    menu.addEntity(buttonParam);
    return (menu);
}

ecs::Scenes mainMenu()
{
    ecs::Core menu = initMenu();

    raylib::Window::SetFullScreen();
    while (!raylib::Window::ShouldClose() && menu.getScene() == ecs::Scenes::Menu) {
        raylib::Window::Clear(raylib::Color::White());
        raylib::Window::BeginDrawing();
        menu.get<ecs::SystemEvent>()->update(menu);
        menu.get<ecs::SystemRender2D>()->update(menu);
        raylib::Window::EndDrawing();
    }
    return (menu.getScene());
}
