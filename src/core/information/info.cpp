/*
** EPITECH PROJECT, 2022
** Project
** File description:
** info
*/

#include "info.hpp"
#include <string>

#define WINDOW_WIDTH         800
#define WINDOW_HEIGHT        600
#define DEFAULT_TRANSPARENCY 128
#define WIDTH_BACKGROUND     224
#define HEIGHT_BACKGROUND    128
#define MARGIN_BORDER        16
#define ICON_SIZE            32
#define NAME_SIZE            24
#define DETAILS_SIZE         16

static raylib::Color playersColor[4] = {
    raylib::Color::Black(),
    raylib::Color::White(),
    raylib::Color::Red(),
    raylib::Color::Blue(),
};

static std::string playersIcon[4] = {"assets/32_black_among_us.png", "assets/32_white_among_us.png", "assets/32_red_among_us.png", "assets/32_blue_among_us.png"};

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

static ecs::IEntity *displayPlayerInfos(std::size_t count, bool TopBottom, bool LeftRight)
{
    ecs::IEntity *entity = new ecs::IEntity();
    raylib::Vector2 positionIcon = {MARGIN_BORDER, MARGIN_BORDER};
    raylib::Vector2 positionText = {};

    if (!TopBottom)
        positionIcon.y = MARGIN_BORDER;
    else
        positionIcon.y = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    positionText.y = positionIcon.y;
    positionIcon.y -= ICON_SIZE / 2;
    if (!LeftRight)
        positionIcon.x = MARGIN_BORDER;
    else
        positionIcon.x = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    positionText.x = positionIcon.x + WIDTH_BACKGROUND / 3;
    entity->add<ComponentTexture>(playersIcon[count], positionIcon);
    entity->add<ComponentText>("assets/NewAthletic.ttf", "Player #" + std::to_string(count + 1), positionText, NAME_SIZE, playersColor[1]);
    entity->add<ComponentDrawable>(true, false);
    return (entity);
}

static ecs::IEntity *displayBotIcon(bool TopBottom, bool LeftRight)
{
    ecs::IEntity *botIcon = new ecs::IEntity();
    raylib::Vector2 position = {MARGIN_BORDER, MARGIN_BORDER};

    if (!TopBottom)
        position.y = MARGIN_BORDER;
    else
        position.y = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    position.y -= ICON_SIZE / 2;
    if (!LeftRight)
        position.x = MARGIN_BORDER;
    else
        position.x = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    position.x += ICON_SIZE * 1.08;

    botIcon->add<ComponentTexture>("assets/bot.png", position);
    botIcon->add<ComponentDrawable>(true, false);
    return (botIcon);
}

void displayInformations(ecs::Core &core)
{
    std::size_t count = 0;
    ecs::IEntity *players = new ecs::IEntity();
    ecs::IEntity *bots = new ecs::IEntity();
    bool TopBottom = false;
    bool LeftRight = false;

    players->add<ComponentBombs>(4);
    bots->add<ComponentBombs>(4);
    players->add<ComponentControllable>();
    core.addEntity(players);
    core.addEntity(bots);
    core.addEntity(players);
    core.addEntity(bots);
    std::vector<ecs::IEntity *> entities = core.getEntities();
    for (auto &entity : entities) {
        if (entity->has<ComponentBombs>()) { //// Change to ComponentHealth
            // It's a player/bot
            TopBottom = count / 2;
            LeftRight = count % 2;
            core.addEntity(createBackground(TopBottom, LeftRight, playersColor[count]));
            core.addEntity(displayPlayerInfos(count, TopBottom, LeftRight));
            if (entity->has<ComponentControllable>()) {
                // It's a player
            } else {
                // It's a bot
                core.addEntity(displayBotIcon(TopBottom, LeftRight));
            }
            count++;
        }
    }
}
