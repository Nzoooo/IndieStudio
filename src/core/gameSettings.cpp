/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** gameSettings
*/

#include "gameSettings.hpp"

static ecs::IEntity *createButton(ecs::Core &menu, raylib::Vector2 posButton, std::string textButton, raylib::Vector2 posText)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentButton>(posButton, textButton, posText, 50.0);
    buttonEntity->add<ComponentClickable>();
    buttonEntity->get<ComponentButton>()->setIdButton(menu.getNbButtons());
    menu.increaseNbButtons(1);
    return (buttonEntity);
}

static int stringLen(const std::string text)
{
    return (text.length());
}

static ecs::Core initSettings()
{
    ecs::Core menu;
    ecs::IEntity *buttonAddBot = createButton(
        menu, raylib::Vector2(1920 / 3.33f - 200, 300.0), "add AI", raylib::Vector2((1920 / 3.33f) - (stringLen("add AI") * 28) / 2.0f, 300 + 35.0));
    ecs::IEntity *buttonRemoveBot = createButton(menu, raylib::Vector2(1920 / 3.33f + 600, 300.0), "remove AI",
        raylib::Vector2((1920 / 3.33f + (1920 / 3.33f)) + (stringLen("remove AI") * 25) / 2.0f, 300 + 35.0));
    buttonAddBot->get<ComponentButton>()->setState(true);
    ecs::IEntity *nbBot = new ecs::IEntity();
    nbBot->add<ComponentDrawable>(true, false);
    nbBot->add<ComponentText>("assets/NewAthletic.ttf", "0", raylib::Vector2(1920 / 2.0f - (stringLen("0") * 25), 320.0), 70, raylib::Color::White(), "nbBot");
    ecs::IEntity *buttonAddBomb = createButton(
        menu, raylib::Vector2(1920 / 3.33f - 200, 450.0), "add Bomb", raylib::Vector2((1920 / 3.33f) - (stringLen("add Bomb") * 28) / 2.0f, 450.0 + 35.0));
    ecs::IEntity *buttonRemoveBomb = createButton(menu, raylib::Vector2(1920 / 3.33f + 600, 450.0), "remove Bomb",
        raylib::Vector2((1920 / 3.33f + (1920 / 3.33f)) + (stringLen("remove Bomb") * 14) / 2.0f, 450.0 + 35.0));
    ecs::IEntity *nbBomb = new ecs::IEntity();
    nbBomb->add<ComponentDrawable>(true, false);
    nbBomb->add<ComponentText>(
        "assets/NewAthletic.ttf", "3", raylib::Vector2(1920 / 2.0f - (stringLen("3") * 25), 470.0), 70, raylib::Color::White(), "nbBomb");
    ecs::IEntity *buttonBonus = createButton(
        menu, raylib::Vector2(1920 / 3.33f - 200, 600.0), "Bonus", raylib::Vector2((1920 / 3.33f) - (stringLen("Bonus") * 28) / 2.0f, 600.0 + 35.0));
    ecs::IEntity *boolBonus = new ecs::IEntity();
    boolBonus->add<ComponentDrawable>(true, false);
    boolBonus->add<ComponentText>(
        "assets/NewAthletic.ttf", "yes", raylib::Vector2(1920 / 2.0f - (stringLen("yes") * 15), 620.0), 70, raylib::Color::White(), "boolBonus");
    ecs::IEntity *startGameButton = createButton(menu, raylib::Vector2(1480.0f, 940.0f), "Start Game", raylib::Vector2(1550.0f, 975.0f));
    ecs::IEntity *goHomeButton = createButton(menu, raylib::Vector2(10.0f, 10.0f), "Go back", raylib::Vector2(100.0f, 45.0f));
    ecs::IEntity *background = new ecs::IEntity();
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTexture>("assets/connectPlayers/bgConnectPlayers.png", raylib::Vector2(0, 0));
    ecs::IEntity *musicMenu = new ecs::IEntity();
    musicMenu->add<ComponentMusic>("assets/audios/MusicMenu.mp3");
    musicMenu->setLabel("MusicMenu");
    musicMenu->get<ComponentMusic>()->getMusic().SetVolume(0.2f);
    menu.setScene(ecs::Scenes::GameSettings);

    menu.add<ecs::SystemRender2D>();
    menu.add<ecs::SystemEvent>();
    menu.addEntity(background);
    menu.addEntity(buttonAddBot);
    menu.addEntity(nbBot);
    menu.addEntity(buttonRemoveBot);
    menu.addEntity(buttonAddBomb);
    menu.addEntity(nbBomb);
    menu.addEntity(buttonRemoveBomb);
    menu.addEntity(buttonBonus);
    menu.addEntity(boolBonus);
    menu.addEntity(startGameButton);
    menu.addEntity(goHomeButton);
    menu.addEntity(musicMenu);
    return (menu);
}

ecs::Scenes gameSettings(std::vector<int> &Settings, std::vector<int> &idControllers)
{
    ecs::Core menu = initSettings();

    menu.getEntity("MusicMenu")->get<ComponentMusic>()->getMusic().Play();
    menu.get<ecs::SystemEvent>()->nbController = idControllers.size();
    printf("nb controler = %d\n", menu.get<ecs::SystemEvent>()->nbController);
    while (!raylib::Window::ShouldClose() && menu.getScene() == ecs::Scenes::GameSettings) {
        menu.getEntity("MusicMenu")->get<ComponentMusic>()->getMusic().Update();
        raylib::Window::BeginDrawing();
        raylib::Window::Clear(raylib::Color::White());
        menu.get<ecs::SystemEvent>()->update(menu);
        menu.get<ecs::SystemRender2D>()->update(menu);
        raylib::Window::EndDrawing();
    }
    menu.getEntity("MusicMenu")->get<ComponentMusic>()->getMusic().Stop();
    for (auto *it : menu.getEntities()) {
        if (it->has<ComponentText>() && it->get<ComponentText>()->getLabel().compare("nbBot") == 0)
            Settings[0] = std::stoi(it->get<ComponentText>()->getText());
        if (it->has<ComponentText>() && it->get<ComponentText>()->getLabel().compare("nbBomb") == 0)
            Settings[1] = std::stoi(it->get<ComponentText>()->getText());
        if (it->has<ComponentText>() && it->get<ComponentText>()->getLabel().compare("boolBonus") == 0) {
            if (it->get<ComponentText>()->getText().compare("yes") == 0)
                Settings[2] = 1;
            else
                Settings[2] = 0;
        }
    }
    return (menu.getScene());
}
