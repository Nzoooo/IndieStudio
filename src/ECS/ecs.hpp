/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ecs
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include "Components/AllComponents.hpp"
#include "Entities/IEntity.hpp"
#include "Systems/ISystem.hpp"
#include "Systems/SystemCollision.hpp"
#include "Systems/SystemEvent.hpp"
#include "Systems/SystemExemple.hpp"
#include "Systems/SystemExplosion.hpp"
#include "Systems/SystemRender2D.hpp"
#include "Systems/SystemRender3D.hpp"
#include "Systems/SystemIA.hpp"
#include "raylib/include/Camera3D.hpp"

#define BASE_SPEED_PLAYERS (0.03f)

namespace ecs
{
    enum Scenes { Menu, ConnectPlayers, Pause, GameSettings, Game, Win, Close, GameSave };
    enum GameStartMode { NONE, Restart, Load };

    class Core {
      private:
        std::vector<ecs::IEntity *> _entities;
        std::vector<ecs::ISystem *> _systems;
        bool _stopped;
        ecs::Scenes _scene;
        int _nbButtons = 0;
        ecs::GameStartMode _start_mode;

      public:
        Core();
        ~Core();
        template <typename T> T *get();
        template <typename T, typename... U> void add(U &&...args);
        template <typename T> bool has() const;
        template <typename T> void remove();

        void run();
        void update();
        void stop();

        unsigned int addEntity(ecs::IEntity *e);
        ecs::IEntity *getEntity(unsigned int const id);
        ecs::IEntity *getEntity(std::string label);
        void removeEntityIterator(std::vector<ecs::IEntity *>::iterator it);
        void removeEntity(unsigned int const i);
        std::vector<ecs::IEntity *> &getEntities();
        ecs::Scenes getScene();
        void setScene(ecs::Scenes scene);
        void increaseNbButtons(int increment);
        int getNbButtons() const;
        ecs::GameStartMode getStartMode() const;
        void setStartMode(ecs::GameStartMode start_mode);

        raylib::Camera3D _camera;
    };

    template <typename T> T *ecs::Core::get()
    {
        if (has<T>() == false)
            std::cout << "System not found" << std::endl;
        return static_cast<T *>(_systems[ecs::TemplateSystem<T>::getId()]);
    }

    template <typename T, typename... U> void ecs::Core::add(U &&...args)
    {
        if (has<T>() == true)
            std::cout << "System already exists" << std::endl;

        unsigned int id = ecs::TemplateSystem<T>::getId();
        if (id >= _systems.size())
            _systems.resize(id + 1);
        _systems[id] = new T(std::forward<U>(args)...);
    }

    template <typename T> bool ecs::Core::has() const
    {
        unsigned int id = ecs::TemplateSystem<T>::getId();
        if (id < _systems.size() && _systems[id])
            return (true);
        else
            return (false);
    }

    template <typename T> void ecs::Core::remove()
    {
        if (has<T>() == false)
            std::cout << "System not found" << std::endl;
        delete _systems[ecs::TemplateSystem<T>::getId()];
    }
} // namespace ecs

#endif /* !ECS_HPP_ */
