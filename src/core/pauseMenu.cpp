/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** pauseMenu
*/

#include "pauseMenu.hpp"
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

static ecs::Core initMenu()
{
    ecs::Core menu;
    ecs::IEntity *buttonResume = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 300.0), "Resume Game");
    buttonResume->get<ComponentButton>()->setState(true);
    ecs::IEntity *buttonSave = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 450.0), "Save Game");
    ecs::IEntity *buttonBack = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 600.0), "Go to the menu");
    ecs::IEntity *buttonExit = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 750.0), "Exit");
    ecs::IEntity *backgroundSetting = new ecs::IEntity();
    backgroundSetting->add<ComponentDrawable>(true, false);
    backgroundSetting->add<ComponentTexture>("assets/backround_pause.png", raylib::Vector2(0, 0));
    ecs::IEntity *background = new ecs::IEntity();
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTexture>("assets/background.png", raylib::Vector2(0, 0));
    menu.setScene(ecs::Scenes::Pause);

    menu.add<ecs::SystemRender2D>();
    menu.add<ecs::SystemEvent>();
    menu.addEntity(background);
    menu.addEntity(backgroundSetting);
    menu.addEntity(buttonResume);
    menu.addEntity(buttonSave);
    menu.addEntity(buttonExit);
    menu.addEntity(buttonBack);
    return (menu);
}

ecs::Scenes pauseMenu()
{
    ecs::Core menu = initMenu();

    raylib::Window::SetFullScreen();
    while (!raylib::Window::ShouldClose() && menu.getScene() == ecs::Scenes::Pause) {
        raylib::Window::Clear(raylib::Color::White());
        raylib::Window::BeginDrawing();
        menu.get<ecs::SystemEvent>()->update(menu);
        menu.get<ecs::SystemRender2D>()->update(menu);
        raylib::Window::EndDrawing();
    }
    return (menu.getScene());
}
