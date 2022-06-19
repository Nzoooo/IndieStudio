/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ecs
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include "Components/ComponentBombs.hpp"
#include "Components/ComponentButton.hpp"
#include "Components/ComponentClickable.hpp"
#include "Components/ComponentCollider.hpp"
#include "Components/ComponentControllable.hpp"
#include "Components/ComponentCube.hpp"
#include "Components/ComponentDrawable.hpp"
#include "Components/ComponentExplodable.hpp"
#include "Components/ComponentExplosion.hpp"
#include "Components/ComponentFireBlast.hpp"
#include "Components/ComponentKillable.hpp"
#include "Components/ComponentKills.hpp"
#include "Components/ComponentMesh.hpp"
#include "Components/ComponentModel.hpp"
#include "Components/ComponentMovable.hpp"
#include "Components/ComponentMusic.hpp"
#include "Components/ComponentPickable.hpp"
#include "Components/ComponentRectangle.hpp"
#include "Components/ComponentSound.hpp"
#include "Components/ComponentText.hpp"
#include "Components/ComponentTexture.hpp"
#include "Components/ComponentTransform.hpp"
#include "Components/ComponentTransparency.hpp"
#include "Entities/IEntity.hpp"
#include "Systems/ISystem.hpp"
#include "Systems/SystemCollision.hpp"
#include "Systems/SystemEvent.hpp"
#include "Systems/SystemExemple.hpp"
#include "Systems/SystemExplosion.hpp"
#include "Systems/SystemRender2D.hpp"
#include "Systems/SystemRender3D.hpp"
#include "raylib/include/Camera3D.hpp"

#define BASE_SPEED_PLAYERS (0.03f)

namespace ecs
{
    enum Scenes { Menu, ConnectPlayers, Pause, GameSettings, Game, Win, Close };

    class Core {
      private:
        std::vector<ecs::IEntity *> _entities;
        std::vector<ecs::ISystem *> _systems;
        bool _stopped;
        ecs::Scenes _scene;
        int _nbButtons = 0;

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
