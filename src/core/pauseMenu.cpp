/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** pauseMenu
*/

#include "pauseMenu.hpp"
#include "ECS/ecs.hpp"
#include "save/save.hpp"

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
    ecs::IEntity *buttonResume = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 450.0), "Resume Game");
    buttonResume->get<ComponentButton>()->setState(true);
    ecs::IEntity *buttonSave = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 600.0), "Save Game");
    ecs::IEntity *buttonBack = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 750.0), "Go to the menu");
    ecs::IEntity *buttonExit = createButton(menu, raylib::Vector2(1920 / 2.0f - 358 / 2.0f, 900.0), "Exit");
    ecs::IEntity *background = new ecs::IEntity();
    background->add<ComponentDrawable>(true, false);
    background->add<ComponentTexture>("assets/bgPause.png", raylib::Vector2(0, 0));
    ecs::IEntity *musicPause = new ecs::IEntity();
    musicPause->add<ComponentMusic>("assets/audios/MusicMenu.mp3");
    musicPause->setLabel("MusicPause");
    musicPause->get<ComponentMusic>()->getMusic().SetVolume(0.2f);
    ecs::IEntity *soundClick = new ecs::IEntity();
    soundClick->add<ComponentSound>("assets/audios/SoundClick.mp3");
    soundClick->setLabel("SoundClick");
    soundClick->get<ComponentSound>()->getSound().SetVolume(0.5f);
    menu.setScene(ecs::Scenes::Pause);

    menu.add<ecs::SystemRender2D>();
    menu.add<ecs::SystemEvent>();
    menu.addEntity(background);
    menu.addEntity(buttonResume);
    menu.addEntity(buttonSave);
    menu.addEntity(buttonBack);
    menu.addEntity(buttonExit);
    menu.addEntity(musicPause);
    menu.addEntity(soundClick);
    return (menu);
}

ecs::Scenes pauseMenu(ecs::Core &core_game)
{
    ecs::Core menu = initMenu();

    menu.getEntity("MusicPause")->get<ComponentMusic>()->getMusic().Play();
    while (menu.getScene() == ecs::Scenes::Pause) {
        menu.getEntity("MusicPause")->get<ComponentMusic>()->getMusic().Update();
        raylib::Window::BeginDrawing();
        raylib::Window::Clear(raylib::Color::White());
        menu.get<ecs::SystemEvent>()->update(menu);
        if (menu.getScene() == ecs::Scenes::GameSave) {
            Save saver;
            saver.saveCore(core_game);
            menu.setScene(ecs::Scenes::Pause);
        }
        menu.get<ecs::SystemRender2D>()->update(menu);
        raylib::Window::EndDrawing();
    }
    menu.getEntity("MusicPause")->get<ComponentMusic>()->getMusic().Stop();
    return (menu.getScene());
}
