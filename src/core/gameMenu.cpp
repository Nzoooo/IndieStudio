/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** gameMenu
*/

/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** mainMenu
*/

#include "gameMenu.hpp"

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

static ecs::Core initSettings()
{
    ecs::Core settings;
    ecs::IEntity *backgroung = new ecs::IEntity();
    backgroung->add<ComponentDrawable>(true, false);
    backgroung->add<ComponentTexture>("assets/background.png", raylib::Vector2(0, 0));
    settings.setScene(ecs::Scenes::GameSettings);

    settings.add<ecs::SystemRender2D>();
    settings.add<ecs::SystemEvent>();
    settings.addEntity(backgroung);
    return (settings);
}

ecs::Scenes gameMenu()
{
    ecs::Core settings = initSettings();

    while (!raylib::Window::ShouldClose() && settings.getScene() == ecs::Scenes::GameSettings) {
        raylib::Window::BeginDrawing();
        raylib::Window::Clear(raylib::Color::White());
        settings.get<ecs::SystemEvent>()->update(settings);
        settings.get<ecs::SystemRender2D>()->update(settings);
        raylib::Window::EndDrawing();
    }
    return (settings.getScene());
}
