/*
** EPITECH PROJECT, 2022
** Project
** File description:
** info
*/

#include "info.hpp"
#include <string>

#define WINDOW_WIDTH         1920
#define WINDOW_HEIGHT        1080
#define DEFAULT_TRANSPARENCY 96
#define WIDTH_BACKGROUND     384
#define HEIGHT_BACKGROUND    220
#define MARGIN_BORDER        32
#define ICON_SIZE            64
#define DETAILS_ICON_SIZE    16
#define NAME_SIZE            32
#define DETAILS_SIZE         26

static raylib::Color playersColor[4] = {
    raylib::Color::Black(),
    raylib::Color::White(),
    raylib::Color::Red(),
    raylib::Color::Blue(),
};

static std::string playersIcon[4] = {
    "assets/64/black_among_us.png", "assets/64/white_among_us.png", "assets/64/red_among_us.png", "assets/64/blue_among_us.png"};

static ecs::IEntity *createBackground(bool topBottom, bool leftRight, raylib::Color color)
{
    ecs::IEntity *background = new ecs::IEntity();
    size_t marginTop = 0;
    size_t marginLeft = 0;

    if (!topBottom)
        marginTop = MARGIN_BORDER;
    else
        marginTop = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    if (!leftRight)
        marginLeft = MARGIN_BORDER;
    else
        marginLeft = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTransparency>(DEFAULT_TRANSPARENCY);
    background->add<ComponentRectangle>(marginLeft, marginTop, WIDTH_BACKGROUND, HEIGHT_BACKGROUND);
    background->get<ComponentRectangle>()->setColor(background->get<ComponentTransparency>()->sumWithColor(color));
    return (background);
}

static ecs::IEntity *displayPlayerHeader(std::size_t count, bool topBottom, bool leftRight)
{
    ecs::IEntity *entity = new ecs::IEntity();
    raylib::Vector2 iconPosition = {MARGIN_BORDER, MARGIN_BORDER};
    raylib::Vector2 textPosition = {};

    if (!topBottom)
        iconPosition.y = MARGIN_BORDER;
    else
        iconPosition.y = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    textPosition.y = iconPosition.y + MARGIN_BORDER * 0.16;
    iconPosition.y -= ICON_SIZE / 2;
    if (!leftRight)
        iconPosition.x = MARGIN_BORDER;
    else
        iconPosition.x = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    textPosition.x = iconPosition.x + WIDTH_BACKGROUND / 3;
    entity->add<ComponentTexture>(playersIcon[count], iconPosition);
    entity->add<ComponentText>("assets/CollegiateBlackFLF.ttf", "PLAYER #" + std::to_string(count + 1), textPosition, NAME_SIZE, raylib::Color::White());
    entity->add<ComponentDrawable>(true, false);
    return (entity);
}

static ecs::IEntity *displayBotIcon(bool topBottom, bool leftRight)
{
    ecs::IEntity *botIcon = new ecs::IEntity();
    raylib::Vector2 position = {MARGIN_BORDER, MARGIN_BORDER};

    if (!topBottom)
        position.y = MARGIN_BORDER;
    else
        position.y = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    position.y -= ICON_SIZE / 2;
    if (!leftRight)
        position.x = MARGIN_BORDER;
    else
        position.x = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    position.x += ICON_SIZE * 0.96;

    botIcon->add<ComponentTexture>("assets/64/bot.png", position);
    botIcon->add<ComponentDrawable>(true, false);
    return (botIcon);
}

static ecs::IEntity *displayBombs(ecs::IEntity *entity, bool topBottom, bool leftRight)
{
    ecs::IEntity *bomb = new ecs::IEntity();
    raylib::Vector2 iconPosition = {MARGIN_BORDER, MARGIN_BORDER};
    raylib::Vector2 textPosition = {MARGIN_BORDER, MARGIN_BORDER};

    if (!topBottom)
        iconPosition.y = MARGIN_BORDER;
    else
        iconPosition.y = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    iconPosition.y += NAME_SIZE * 2;
    textPosition.y = iconPosition.y + DETAILS_ICON_SIZE / 2;
    if (!leftRight)
        iconPosition.x = MARGIN_BORDER;
    else
        iconPosition.x = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    iconPosition.x += MARGIN_BORDER;
    textPosition.x = iconPosition.x + DETAILS_ICON_SIZE * 3;

    bomb->add<ComponentTexture>("assets/16/bomb_icon.png", iconPosition);
    bomb->add<ComponentText>("assets/CollegiateBlackFLF.ttf",
        std::to_string(entity->get<ComponentBombs>()->getNbCurrBombs()) + "/" + std::to_string(entity->get<ComponentBombs>()->getNbMaxBombs()), textPosition,
        DETAILS_SIZE, raylib::Color::White());
    bomb->add<ComponentDrawable>(true, false);
    return (bomb);
}

static ecs::IEntity *displayRadius(ecs::IEntity *entity, bool topBottom, bool leftRight)
{
    ecs::IEntity *bomb = new ecs::IEntity();
    raylib::Vector2 iconPosition = {MARGIN_BORDER, MARGIN_BORDER};
    raylib::Vector2 textPosition = {MARGIN_BORDER, MARGIN_BORDER};

    if (!topBottom)
        iconPosition.y = MARGIN_BORDER;
    else
        iconPosition.y = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    iconPosition.y += NAME_SIZE * 2 + DETAILS_ICON_SIZE * 3;
    textPosition.y = iconPosition.y + DETAILS_ICON_SIZE / 2;
    if (!leftRight)
        iconPosition.x = MARGIN_BORDER;
    else
        iconPosition.x = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    iconPosition.x += MARGIN_BORDER;
    textPosition.x = iconPosition.x + DETAILS_ICON_SIZE * 3;

    bomb->add<ComponentTexture>("assets/16/radius_icon.png", iconPosition);
    bomb->add<ComponentText>("assets/CollegiateBlackFLF.ttf", std::to_string(entity->get<ComponentExplodable>()->getBlastRange()), textPosition, DETAILS_SIZE,
        raylib::Color::White());
    bomb->add<ComponentDrawable>(true, false);
    return (bomb);
}

static ecs::IEntity *displaySpeed(ecs::IEntity *entity, bool topBottom, bool leftRight)
{
    ecs::IEntity *bomb = new ecs::IEntity();
    raylib::Vector2 iconPosition = {MARGIN_BORDER, MARGIN_BORDER};
    raylib::Vector2 textPosition = {MARGIN_BORDER, MARGIN_BORDER};

    if (!topBottom)
        iconPosition.y = MARGIN_BORDER;
    else
        iconPosition.y = WINDOW_HEIGHT - (HEIGHT_BACKGROUND + MARGIN_BORDER);
    iconPosition.y += NAME_SIZE * 2 + DETAILS_ICON_SIZE * 6;
    textPosition.y = iconPosition.y + DETAILS_ICON_SIZE / 2;
    if (!leftRight)
        iconPosition.x = MARGIN_BORDER;
    else
        iconPosition.x = WINDOW_WIDTH - (WIDTH_BACKGROUND + MARGIN_BORDER);
    iconPosition.x += MARGIN_BORDER;
    textPosition.x = iconPosition.x + DETAILS_ICON_SIZE * 3;

    bomb->add<ComponentTexture>("assets/16/speed_icon.png", iconPosition);
    bomb->add<ComponentText>(
        "assets/CollegiateBlackFLF.ttf", std::to_string(entity->get<ComponentSpeed>()->getSpeed()), textPosition, DETAILS_SIZE, raylib::Color::White());
    bomb->add<ComponentDrawable>(true, false);
    return (bomb);
}

void displayInformations(ecs::Core &core)
{
    std::size_t count = 0;
    ecs::IEntity *players = new ecs::IEntity();
    ecs::IEntity *bots = new ecs::IEntity();
    bool topBottom = false;
    bool leftRight = false;

    players->add<ComponentBombs>(4);
    bots->add<ComponentBombs>(4);
    players->add<ComponentSpeed>(3);
    bots->add<ComponentSpeed>(2);
    players->add<ComponentExplodable>(1, true);
    bots->add<ComponentExplodable>(1, true);
    players->add<ComponentControllable>();
    core.addEntity(players);
    core.addEntity(bots);
    core.addEntity(players);
    core.addEntity(bots);
    std::vector<ecs::IEntity *> entities = core.getEntities();
    for (auto &entity : entities) {
        if (entity->has<ComponentBombs>()) { //// Change to ComponentHealth
            // It's a player/bot
            topBottom = count / 2;
            leftRight = count % 2;
            core.addEntity(createBackground(topBottom, leftRight, playersColor[count]));
            core.addEntity(displayPlayerHeader(count, topBottom, leftRight));
            if (entity->has<ComponentControllable>()) {
                // It's a player
            } else {
                // It's a bot
                core.addEntity(displayBotIcon(topBottom, leftRight));
            }
            core.addEntity(displayBombs(entity, topBottom, leftRight));
            core.addEntity(displayRadius(entity, topBottom, leftRight));
            core.addEntity(displaySpeed(entity, topBottom, leftRight));
            count++;
        }
    }
}