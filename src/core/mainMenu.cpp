/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** mainMenu
*/

#include "../ECS/ecs.hpp"
#include "mainMenu.hpp"

static bool isClicking(raylib::Rectangle *rectangle)
{
    raylib::Mouse mouseIndex;
    if ((mouseIndex.GetX() >= rectangle->x) && (mouseIndex.GetY() >= rectangle->y) && (mouseIndex.GetX() < rectangle->x + rectangle->width) && (mouseIndex.GetY() < rectangle->height + rectangle->y)) {
        if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
            return (true);
    }
    return (false);
}

static ecs::IEntity *createButton(float x, float y, float width, float height)
{
    ecs::IEntity *entity = new ecs::IEntity();

    entity->add<ComponentDrawable>(true, false);
    entity->add<ComponentRectangle>(x, y, width, height);
    entity->add<ComponentClickable>(true);
    return (entity);
}

int mainMenu()
{
    raylib::Window *window;
    ecs::Core menu;
    ecs::IEntity *buttonStart = createButton(200.0, 150.0, 200.0, 75.0);
    ecs::IEntity *buttonRealod = createButton(200.0, 250.0, 200.0, 75.0);
    ecs::IEntity *buttonParam = createButton(200.0, 350.0, 200.0, 75.0);
    window->Init();

    menu.addEntity(buttonParam);
    menu.addEntity(buttonStart);
    menu.addEntity(buttonRealod);

    while (!WindowShouldClose()) {
        ClearBackground(raylib::Color::White());
        window->BeginDrawing();
        for (size_t i = 0; i < 3; i++){
            menu.getEntity(i)->get<ComponentRectangle>()->setColor(raylib::Color::Orange());
            raylib::Rectangle *button = menu.getEntity(i)->get<ComponentRectangle>()->getRectangle();
            button->Draw(menu.getEntity(i)->get<ComponentRectangle>()->getColor());
            if (menu.getEntity(i)->has<ComponentClickable>() == true && isClicking(button) && menu.getEntity(i)->get<ComponentRectangle>()->getRectangle()->y == 150.0) {
                window->EndDrawing();
                return (1);
            }
            else if (menu.getEntity(i)->has<ComponentClickable>() == true && isClicking(button) && menu.getEntity(i)->get<ComponentRectangle>()->getRectangle()->y == 250.0) {
                window->EndDrawing();
                return (1);
            }
            else if (menu.getEntity(i)->has<ComponentClickable>() == true && isClicking(button) && menu.getEntity(i)->get<ComponentRectangle>()->getRectangle()->y == 350.0) {
                window->EndDrawing();
                return (3);
            }
        }
        window->EndDrawing();
    }
    return (-1);
}