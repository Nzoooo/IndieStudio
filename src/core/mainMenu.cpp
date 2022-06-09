/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** mainMenu
*/

#include "../ECS/ecs.hpp"
#include "mainMenu.hpp"

// static bool isClicking(raylib::Rectangle *rectangle)
// {
//     raylib::Mouse mouseIndex;
//     if ((mouseIndex.GetX() >= rectangle->x) && (mouseIndex.GetY() >= rectangle->y) && (mouseIndex.GetX() < rectangle->x + rectangle->width) && (mouseIndex.GetY() < rectangle->height + rectangle->y)) {
//         if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
//             return (true);
//     }
//     return (false);
// }

static ecs::IEntity *createButton(raylib::Vector2 posButton, std::string textButton)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentClickable>();
static ecs::Core initMenu()
{
    ecs::Core menu;
    ecs::IEntity *buttonStart = createButton(raylib::Vector2(800 / 2.0f - 358 / 2.0f, 150.0), "Start Game");
    ecs::IEntity *buttonReload = createButton(raylib::Vector2(800 / 2.0f - 358 / 2.0f, 300.0), "Reload Game");
    ecs::IEntity *buttonParam = createButton(raylib::Vector2(800 / 2.0f - 358 / 2.0f, 450.0), "Settings");
    ecs::IEntity *backgroung = new ecs::IEntity();
    ecs::IEntity *logo = new ecs::IEntity();
    backgroung->add<ComponentDrawable>(true, false);
    backgroung->add<ComponentTexture>("assets/background.png", raylib::Vector2(0, 0));
    logo->add<ComponentDrawable>(true, false);
    logo->add<ComponentTexture>("assets/Logo.png", raylib::Vector2(800 / 2.0f - 200 / 2.0f, 30));
    menu.setScene(ecs::Scenes::Menu);

    menu.add<ecs::SystemRender2D>();
    menu.addEntity(backgroung);
    menu.addEntity(logo);
    menu.addEntity(buttonStart);
    menu.addEntity(buttonParam);
    menu.addEntity(buttonReload);
    return (menu);
}

int mainMenu()
{
    raylib::Window::Init();
    ecs::Core menu = initMenu();

    // raylib::Window::SetFullScreen();
    while (!raylib::Window::ShouldClose()) {
        raylib::Window::Clear(raylib::Color::White());
        raylib::Window::BeginDrawing();
        menu.get<ecs::SystemRender2D>()->update(menu);
        raylib::Window::EndDrawing();
    }
    raylib::Window::Close();
    return (-1);
}