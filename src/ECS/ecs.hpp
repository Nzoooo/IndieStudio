/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ecs
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include "Systems/SystemExemple.hpp"
#include "Components/ComponentMovable.hpp"
#include "Entities/IEntity.hpp"
#include "Systems/ISystem.hpp"

namespace ecs
{
    class Core {
    private:
        std::vector<ecs::IEntity *> _entities;
        std::vector<ecs::ISystem *> _systems;
        bool _stopped;

    public:
        Core();
        ~Core();
        template <typename T>
        T *get();
        template <typename T, typename... U>
        void add(U &&... args);
        template <typename T>
        bool has() const;
        template <typename T>
        void remove();

        void run();
        void update();
        void stop();

        unsigned int addEntity(ecs::IEntity *e);
        unsigned int addSystem(ecs::ISystem *e);
        ecs::IEntity *getEntity(unsigned int const id);
        ecs::ISystem *getSystem(unsigned int const id);
        void removeEntityIterrator(std::vector<ecs::IEntity *>::iterator it);
        void removeSystemIterrator(std::vector<ecs::ISystem *>::iterator it);
        void removeEntity(unsigned int const i);
        void removeSystem(unsigned int const i);
        std::vector<ecs::IEntity *> &getEntities();
        std::vector<ecs::ISystem *> &getSystems();
    };

    template <typename T>
    T *ecs::Core::get() {
        if (has<T>() == false)
            std::cout << "System not found" << std::endl;
        return static_cast<T *>(_systems[ecs::TemplateSystem<T>::getId()]);
    }

    template <typename T, typename... U>
    void ecs::Core::add(U &&... args) {
        if (has<T>() == true)
            std::cout << "System already exists" << std::endl;

        unsigned int id = ecs::TemplateSystem<T>::getId();
        if (id >= _systems.size())
            _systems.resize(id + 1);
        _systems[id] = new T(std::forward<U>(args)...);
    }

    template <typename T>
    bool ecs::Core::has() const {
        unsigned int id = ecs::TemplateSystem<T>::getId();
        if (id < _systems.size() && _systems[id])
            return (true);
        else
            return (false);
    }

    template <typename T>
    void ecs::Core::remove() {
        if (has<T>() == false)
            std::cout << "System not found" << std::endl;
        delete _systems[ecs::TemplateSystem<T>::getId()];
        _systems[ecs::TemplateSystem<T>::getId()] = 0;
    }
}

ecs::Core initEntities();

#endif /* !ECS_HPP_ */
