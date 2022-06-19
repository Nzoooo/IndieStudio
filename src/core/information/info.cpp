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
    raylib::Color::Red(),
    raylib::Color::Blue(),
    raylib::Color::Black(),
    raylib::Color::White(),
};

static std::string playersIcon[4] = {
    "assets/64/red_among_us.png", "assets/64/blue_among_us.png", "assets/64/black_among_us.png", "assets/64/white_among_us.png"};

/// Add the background of the informations
/// @param bool Boolean if it has to be at the bottom or not.
/// @param bool Boolean if it has to be at the right or not.
/// @param raylib::Color Color of the background.
/// @return ecs::IEntity* Pointer to the filled entity.
static ecs::IEntity *createBackground(bool topBottom, bool leftRight, raylib::Color color)
{
    ecs::IEntity *background = new ecs::IEntity();
    std::size_t marginTop = 0;
    std::size_t marginLeft = 0;

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

/// Add the player icon to the informations.
/// @param bool Boolean if it has to be at the bottom or not.
/// @param bool Boolean if it has to be at the right or not.
/// @return ecs::IEntity* Pointer to the filled entity.
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

/// Add the bot icon to the informations.
/// @param bool Boolean if it has to be at the bottom or not.
/// @param bool Boolean if it has to be at the right or not.
/// @return ecs::IEntity* Pointer to the filled entity.
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

/// Add the bomb text and icon to the informations.
/// @param bool Boolean if it has to be at the bottom or not.
/// @param bool Boolean if it has to be at the right or not.
/// @return ecs::IEntity* Pointer to the filled entity.
static ecs::IEntity *displayBombs(bool topBottom, bool leftRight, std::string label)
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

    bomb->add<ComponentTexture>("assets/16/boost_nb_bombs.png", iconPosition);
    bomb->add<ComponentText>("assets/CollegiateBlackFLF.ttf", "0/0", textPosition, DETAILS_SIZE, raylib::Color::White(), label);
    bomb->add<ComponentDrawable>(true, false);
    return (bomb);
}

/// Add the radius text and icon to the informations.
/// @param bool Boolean if it has to be at the bottom or not.
/// @param bool Boolean if it has to be at the right or not.
/// @return ecs::IEntity* Pointer to the filled entity.
static ecs::IEntity *displayRadius(bool topBottom, bool leftRight, std::string label)
{
    ecs::IEntity *radius = new ecs::IEntity();
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

    radius->add<ComponentTexture>("assets/16/boost_radius_bombs.png", iconPosition);
    radius->add<ComponentText>("assets/CollegiateBlackFLF.ttf", "0", textPosition, DETAILS_SIZE, raylib::Color::White(), label);
    radius->add<ComponentDrawable>(true, false);
    return (radius);
}

/// Add the speed text and icon to the informations.
/// @param ecs::IEntity* Pointer to the player entity
/// @param bool Boolean if it has to be at the bottom or not.
/// @param bool Boolean if it has to be at the right or not.
/// @return ecs::IEntity* Pointer to the filled entity.
static ecs::IEntity *displaySpeed(bool topBottom, bool leftRight, std::string label)
{
    ecs::IEntity *speed = new ecs::IEntity();
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

    speed->add<ComponentTexture>("assets/16/boost_speed.png", iconPosition);
    speed->add<ComponentText>("assets/CollegiateBlackFLF.ttf", "0", textPosition, DETAILS_SIZE, raylib::Color::White(), label);
    speed->add<ComponentDrawable>(true, false);
    return (speed);
}

void updateInformations(ecs::Core &core, ecs::IEntity *player)
{
    for (auto *info : core.getEntities()) {
        if (info->has<ComponentTexture>() && info->get<ComponentTexture>()->getPathOldTexture() == "assets/16/boost_speed.png" && info->has<ComponentText>()
            && info->get<ComponentText>()->getLabel() == player->getLabel()) {
            info->get<ComponentText>()->setText(std::to_string(static_cast<int>(player->get<ComponentMovable>()->getSpeed() / BASE_SPEED_PLAYERS)));
        }
        if (info->has<ComponentTexture>() && info->get<ComponentTexture>()->getPathOldTexture() == "assets/16/boost_radius_bombs.png"
            && info->has<ComponentText>() && info->get<ComponentText>()->getLabel() == player->getLabel()) {
            info->get<ComponentText>()->setText(std::to_string(player->get<ComponentExplodable>()->getBlastRange()));
        }
        if (info->has<ComponentTexture>() && info->get<ComponentTexture>()->getPathOldTexture() == "assets/16/boost_nb_bombs.png" && info->has<ComponentText>()
            && info->get<ComponentText>()->getLabel() == player->getLabel()) {
            info->get<ComponentText>()->setText(
                std::to_string(player->get<ComponentBombs>()->getNbCurrBombs()) + "/" + std::to_string(player->get<ComponentBombs>()->getNbMaxBombs()));
        }
    }
}

/// Display informations on the player (Nb bombs, radius of bombs, speed ...).
/// @param &core Reference to the core to add the informations.
void initInformations(ecs::Core &core)
{
    std::size_t count = 0;
    bool topBottom = false;
    bool leftRight = false;

    for (auto *entity : core.getEntities()) {
        if (entity->has<ComponentKills>()) {
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
            core.addEntity(displayBombs(topBottom, leftRight, entity->getLabel()));
            core.addEntity(displayRadius(topBottom, leftRight, entity->getLabel()));
            core.addEntity(displaySpeed(topBottom, leftRight, entity->getLabel()));
            count++;
        }
    }
}
