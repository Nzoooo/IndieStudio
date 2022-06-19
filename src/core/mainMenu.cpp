/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** mainMenu
*/

#include "mainMenu.hpp"

static ecs::IEntity *createButton(ecs::Core &menu, raylib::Vector2 posButton, std::string textButton)
{
    ecs::IEntity *buttonEntity = new ecs::IEntity();

    buttonEntity->add<ComponentDrawable>(true, false);
    buttonEntity->add<ComponentButton>(posButton, textButton);
    buttonEntity->add<ComponentClickable>();
    buttonEntity->get<ComponentButton>()->setIdButton(menu.getNbButtons());
    menu.increaseNbButtons(1);
    return (buttonEntity);
}

static ecs::Core initMenu()
{
    ecs::Core menu;
    ecs::IEntity *buttonStart = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 450.0), "Start Game");
    buttonStart->get<ComponentButton>()->setState(true);
    ecs::IEntity *buttonReload = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 600.0), "Reload Game");
    ecs::IEntity *buttonParam = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 750.0), "Exit");
    ecs::IEntity *background = new ecs::IEntity();
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTexture>("assets/background.png", raylib::Vector2(0, 0));
    ecs::IEntity *musicMenu = new ecs::IEntity();
    musicMenu->add<ComponentMusic>("assets/audios/MusicMenu.mp3");
    musicMenu->setLabel("MusicMenu");
    musicMenu->get<ComponentMusic>()->getMusic().SetVolume(0.2f);
    ecs::IEntity *soundClick = new ecs::IEntity();
    soundClick->add<ComponentSound>("assets/audios/SoundClick.mp3");
    soundClick->setLabel("SoundClick");
    soundClick->get<ComponentSound>()->getSound().SetVolume(0.5f);
    menu.setScene(ecs::Scenes::Menu);

    menu.add<ecs::SystemRender2D>();
    menu.add<ecs::SystemEvent>();
    menu.addEntity(background);
    menu.addEntity(buttonStart);
    menu.addEntity(buttonReload);
    menu.addEntity(buttonParam);
    menu.addEntity(musicMenu);
    menu.addEntity(soundClick);
    return (menu);
}

ecs::Scenes mainMenu(ecs::Core &core)
{
    ecs::Core menu = initMenu();

    menu.getEntity("MusicMenu")->get<ComponentMusic>()->getMusic().Play();
    while (menu.getScene() == ecs::Scenes::Menu) {
        menu.getEntity("MusicMenu")->get<ComponentMusic>()->getMusic().Update();
        raylib::Window::BeginDrawing();
        raylib::Window::Clear(raylib::Color::White());
        raylib::Window::BeginDrawing();
        menu.get<ecs::SystemEvent>()->update(menu);
        core.setStartMode(menu.getStartMode());
        menu.get<ecs::SystemRender2D>()->update(menu);
        raylib::Window::EndDrawing();
    }
    return (menu.getScene());
}