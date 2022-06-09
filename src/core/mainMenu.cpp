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

static ecs::IEntity *createButton2(raylib::Vector2 posButton)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentButton>(posButton, "../assets/menuAsset.png");
    buttonEntity->add<ComponentClickable>();
    return (buttonEntity);
}

static ecs::IEntity *createButton(float x, float y, float width, float height)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentRectangle>(x, y, width, height, raylib::Color::Orange());
    buttonEntity->add<ComponentClickable>();
    return (buttonEntity);
}

static ecs::IEntity *createFont(raylib::Vector2 pos, std::string text, size_t size)
{
    ecs::IEntity *textEntity = new ecs::IEntity();

    textEntity->add<ComponentClickable>();
    textEntity->add<ComponentText>("../assets/NewAthletic.ttf", text, pos, size, raylib::Color::White());
    return (textEntity);
}

static ecs::Core initMenu()
{
    ecs::Core menu;
    raylib::Vector2 pos = {270.0, 163.0};
    ecs::IEntity *buttonStart = createButton2((raylib::Vector2){0, 0});
    ecs::IEntity *buttonReload = createButton(200.0, 250.0, 400.0, 75.0);
    ecs::IEntity *buttonParam = createButton(200.0, 350.0, 400.0, 75.0);
    pos = {270, 260};
    ecs::IEntity *TextReload = createFont(pos, "Reload Game", 55);
    pos = {270, 360};
    ecs::IEntity *TextParam = createFont(pos, "Settings", 55);
    ecs::IEntity *backgroung = new ecs::IEntity();
    ecs::IEntity *logo = new ecs::IEntity();
    pos = {0, 0};
    backgroung->add<ComponentTexture>("../assets/placeholder.png", pos);
    pos = {50, 50};
    logo->add<ComponentTexture>("../assets/Logo.png", pos);

    menu.addEntity(backgroung);
    menu.addEntity(logo);
    menu.addEntity(buttonStart);
    menu.addEntity(buttonParam);
    menu.addEntity(buttonReload);
    menu.addEntity(TextStart);
    menu.addEntity(TextReload);
    menu.addEntity(TextParam);
    return (menu);
}

int mainMenu()
{
    raylib::Window *window;
    window->Init();
    ecs::Core menu = initMenu();
    
    while (!WindowShouldClose()) {
        ClearBackground(raylib::Color::White());
        window->BeginDrawing();
        menu.getEntity(0)->get<ComponentTexture>()->Draw();
        menu.getEntity(1)->get<ComponentTexture>()->Draw();
        menu.getEntity(2)->get<ComponentButton>()->Draw();
        for (size_t i = 3; i < 5; i++)
            menu.getEntity(i)->get<ComponentRectangle>()->Draw();

        for (size_t i = 5; i < 8; i++)
            menu.getEntity(i)->get<ComponentText>()->Draw();
        window->EndDrawing();
    }
    return (-1);
}