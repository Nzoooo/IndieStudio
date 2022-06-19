/*
** EPITECH PROJECT, 2022
** connectPlayers
** File description:
** connectPlayers
*/

#include "connectPlayers.hpp"

static ecs::IEntity *createButton(ecs::Core &connect, raylib::Vector2 posButton, std::string textButton, raylib::Vector2 posText)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentButton>(posButton, textButton, posText, 50.0f);
    buttonEntity->add<ComponentClickable>();
    buttonEntity->get<ComponentButton>()->setIdButton(connect.getNbButtons());
    connect.increaseNbButtons(1);
    return (buttonEntity);
}

ecs::Core initConnectPlayers()
{
    ecs::Core connect;
    ecs::IEntity *player = new ecs::IEntity();
    player->add<ComponentDrawable>(true, false);
    player->add<ComponentModel>("assets/models3D/Among_Us_red.obj", raylib::Vector3(-5.0f, -1.0f, 0.5f), raylib::Vector3(0.7f, 0.7f, 0.7f));
    player->add<ComponentTexture>("assets/connectPlayers/AmongUsTrsp.png", raylib::Vector2(160.0f, 330.0f), raylib::Vector2(255.0f, 820.0f));
    player->add<ComponentControllable>();
    ecs::IEntity *player2 = new ecs::IEntity();
    player2->add<ComponentDrawable>(true, false);
    player2->add<ComponentModel>("assets/models3D/Among_Us_blue.obj", raylib::Vector3(-1.7f, -1.0f, 0.5f), raylib::Vector3(0.7f, 0.7f, 0.7f));
    player2->add<ComponentTexture>("assets/connectPlayers/AmongUsTrsp.png", raylib::Vector2(580.0f, 330.0f), raylib::Vector2(675.0f, 820.0f));
    player2->add<ComponentControllable>();
    ecs::IEntity *player3 = new ecs::IEntity();
    player3->add<ComponentDrawable>(true, false);
    player3->add<ComponentModel>("assets/models3D/Among_Us_black.obj", raylib::Vector3(1.55f, -1.0f, 0.5f), raylib::Vector3(0.7f, 0.7f, 0.7f));
    player3->add<ComponentTexture>("assets/connectPlayers/AmongUsTrsp.png", raylib::Vector2(1000.0f, 330.0f), raylib::Vector2(1095.0f, 820.0f));
    player3->add<ComponentControllable>();
    ecs::IEntity *player4 = new ecs::IEntity();
    player4->add<ComponentDrawable>(true, false);
    player4->add<ComponentModel>("assets/models3D/Among_Us_white.obj", raylib::Vector3(4.8f, -1.0f, 0.5f), raylib::Vector3(0.7f, 0.7f, 0.7f));
    player4->add<ComponentTexture>("assets/connectPlayers/AmongUsTrsp.png", raylib::Vector2(1420.0f, 330.0f), raylib::Vector2(1515.0f, 820.0f));
    player4->add<ComponentControllable>();
    ecs::IEntity *scanner = new ecs::IEntity();
    scanner->add<ComponentDrawable>(true, false);
    scanner->add<ComponentTexture>("assets/connectPlayers/scanner.png", raylib::Vector2(120.0f, 580.0f));
    ecs::IEntity *scanner2 = new ecs::IEntity();
    scanner2->add<ComponentDrawable>(true, false);
    scanner2->add<ComponentTexture>("assets/connectPlayers/scanner.png", raylib::Vector2(540.0f, 580.0f));
    ecs::IEntity *scanner3 = new ecs::IEntity();
    scanner3->add<ComponentDrawable>(true, false);
    scanner3->add<ComponentTexture>("assets/connectPlayers/scanner.png", raylib::Vector2(960.0f, 580.0f));
    ecs::IEntity *scanner4 = new ecs::IEntity();
    scanner4->add<ComponentDrawable>(true, false);
    scanner4->add<ComponentTexture>("assets/connectPlayers/scanner.png", raylib::Vector2(1380.0f, 580.0f));
    ecs::IEntity *background = new ecs::IEntity();
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTexture>("assets/connectPlayers/bgConnectPlayers.png", raylib::Vector2(0.0f, 0.0f));
    ecs::IEntity *textConnection = new ecs::IEntity();
    textConnection->add<ComponentDrawable>(true, false);
    textConnection->add<ComponentText>("assets/NewAthletic.ttf", "Press      to add a Player", raylib::Vector2(520.0f, 950.0f), 90, raylib::Color::White());
    ecs::IEntity *logoXButton = new ecs::IEntity();
    logoXButton->add<ComponentDrawable>(true, false);
    logoXButton->add<ComponentTexture>("assets/XButton.png", raylib::Vector2(725.0f, 945.0f));
    ecs::IEntity *goHomeButton = createButton(connect, raylib::Vector2(10.0f, 10.0f), "Home", raylib::Vector2(135.0f, 45.0f));
    ecs::IEntity *nothingToSelectButton = createButton(connect, raylib::Vector2(0.0f, 0.0f), "", raylib::Vector2(0.0f, 0.0f));
    std::string trspTexturePath = "assets/connectPlayers/trspTexture.png";
    nothingToSelectButton->get<ComponentButton>()->setTexture(trspTexturePath);
    nothingToSelectButton->get<ComponentButton>()->setState(true);
    ecs::IEntity *startGameButton = createButton(connect, raylib::Vector2(1480.0f, 940.0f), "Start Game", raylib::Vector2(1540.0f, 975.0f));
    startGameButton->get<ComponentButton>()->setIdButton(-connect.getNbButtons() + 1);
    ecs::IEntity *soundClick = new ecs::IEntity();
    soundClick->add<ComponentSound>("assets/audios/SoundClick.mp3");
    soundClick->setLabel("SoundClick");
    soundClick->get<ComponentSound>()->getSound().SetVolume(0.5f);
    connect.setScene(ecs::Scenes::ConnectPlayers);

    connect.add<ecs::SystemRender2D>();
    connect.add<ecs::SystemRender3D>();
    connect.add<ecs::SystemEvent>();
    connect.addEntity(background);
    connect.addEntity(textConnection);
    connect.addEntity(logoXButton);
    connect.addEntity(goHomeButton);
    connect.addEntity(nothingToSelectButton);
    connect.addEntity(startGameButton);
    connect.addEntity(scanner);
    connect.addEntity(scanner2);
    connect.addEntity(scanner3);
    connect.addEntity(scanner4);
    connect.addEntity(player);
    connect.addEntity(player2);
    connect.addEntity(player3);
    connect.addEntity(player4);
    connect.addEntity(soundClick);
    return (connect);
}

ecs::Scenes connectPlayers(ecs::Core &core, std::vector<int> &idControllers)
{
    idControllers.clear();
    ecs::Core connect = initConnectPlayers();
    raylib::Camera3D camera(raylib::Vector3(0.0f, 3.0f, 10.0f), raylib::Vector3(0.0f, 0.0f, 0.0f), raylib::Vector3(0.0f, 1.0f, 0.0f), 45.0f);

    while (connect.getScene() == ecs::Scenes::ConnectPlayers) {
        raylib::Window::BeginDrawing();
        raylib::Window::Clear(raylib::Color::White());
        connect.get<ecs::SystemEvent>()->update(connect);
        connect.get<ecs::SystemRender2D>()->update(connect);
        core.setStartMode(connect.getStartMode());
        camera.BeginMode();
        connect.get<ecs::SystemRender3D>()->update(connect);
        camera.EndMode();
        raylib::Window::EndDrawing();
    }
    for (auto *it : connect.getEntities()) {
        if (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() != -1)
            idControllers.push_back(it->get<ComponentControllable>()->getGamepadId());
    }
    return (connect.getScene());
}
