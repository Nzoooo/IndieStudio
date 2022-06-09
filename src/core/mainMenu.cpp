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

static ecs::IEntity *createButton2(raylib::Vector2 posButton, std::string textButton)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentButton>(posButton, "../assets/menuAsset.png", textButton);
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
    raylib::Vector2 pos = {0, 0};
    ecs::IEntity *buttonStart = createButton2((raylib::Vector2){800 / 2.0f - 358 / 2.0f, 150.0}, "Start Game");
    ecs::IEntity *buttonReload = createButton2((raylib::Vector2){800 / 2.0f - 358 / 2.0f, 300.0}, "Reload Game");
    ecs::IEntity *buttonParam = createButton2((raylib::Vector2){800 / 2.0f - 358 / 2.0f, 450.0}, "Settings");
    ecs::IEntity *backgroung = new ecs::IEntity();
    ecs::IEntity *logo = new ecs::IEntity();
    backgroung->add<ComponentTexture>("../assets/placeholder.png", pos);
    pos = {50, 50};
    logo->add<ComponentTexture>("../assets/Logo.png", pos);

    menu.addEntity(backgroung);
    menu.addEntity(logo);
    menu.addEntity(buttonStart);
    menu.addEntity(buttonParam);
    menu.addEntity(buttonReload);
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
        for (size_t i = 2; i < 5; i++)
            menu.getEntity(i)->get<ComponentButton>()->Draw();
        window->EndDrawing();
    }
    return (-1);
}