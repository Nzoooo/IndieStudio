/*
** EPITECH PROJECT, 2022
** Project
** File description:
** info
*/

#include "info.hpp"

#define WINDOW_WIDTH         800
#define WINDOW_HEIGHT        600
#define DEFAULT_TRANSPARENCY 128
#define WIDTH_BACKGROUND     224
#define HEIGHT_BACKGROUND    128
#define MARGIN_BORDER        16
#define ICON_SIZE            32

static raylib::Color mainPlayersColor[4] = {
    raylib::Color::Black(),
    raylib::Color::White(),
    raylib::Color::Red(),
    raylib::Color::Blue(),
};

static ecs::IEntity *createBackground(bool TopBottom, bool LeftRight, raylib::Color color)
{
    ecs::IEntity *background = new ecs::IEntity();
    size_t margin_top = 0;
    size_t margin_left = 0;

    if (!TopBottom)
        margin_top = MARGIN_BORDER;
    else
        margin_top = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    if (!LeftRight)
        margin_left = MARGIN_BORDER;
    else
        margin_left = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTransparency>(DEFAULT_TRANSPARENCY);
    background->add<ComponentRectangle>(margin_left, margin_top, WIDTH_BACKGROUND, HEIGHT_BACKGROUND);
    background->get<ComponentRectangle>()->setColor(background->get<ComponentTransparency>()->sumWithColor(color));
    return (background);
}

void displayInformations(ecs::Core &core)
{
    std::size_t count = 0;
    ecs::IEntity *players = new ecs::IEntity();
    ecs::IEntity *bots = new ecs::IEntity();

    players->add<ComponentKillable>();
    bots->add<ComponentKillable>();
    players->add<ComponentControllable>();
    core.addEntity(players);
    core.addEntity(bots);
    core.addEntity(players);
    core.addEntity(bots);
    for (auto &entity : core.getEntities()) {
        if (entity->has<ComponentKillable>()) { // Change to ComponentHealth
            // It's a player/bot
            core.addEntity(createBackground(count / 2, count % 2, mainPlayersColor[count]));
            core.addEntity(displayMainIcon(count / 2, count % 2));
            if (entity->has<ComponentControllable>()) {
                // It's a player
            } else {
                // It's a bot
                core.addEntity(displayBotIcon(count / 2, count % 2));
            }
            count++;
        }
    }
}
