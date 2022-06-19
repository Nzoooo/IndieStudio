/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** IEntity
*/

#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include "../Components/IComponent.hpp"

namespace ecs
{
    class IEntity {
      private:
        std::vector<ecs::IComponent *> _components;
        std::string _label = "";

      public:
        IEntity()
        {
            _components = {0};
        }
        ~IEntity();
        std::vector<ecs::IComponent *> &getAllComponents();
        void setLabel(std::string label);
        std::string getLabel() const;
        template <typename T> T *get();
        template <typename T> bool has() const;
        template <typename T> void remove();
        template <typename T, typename... U> void add(U &&...args);
    };
} // namespace ecs

template <typename T> T *ecs::IEntity::get()
{
    if (has<T>() == false)
        std::cout << "Component not found" << std::endl;
    return static_cast<T *>(_components[ecs::TemplateComponent<T>::getId()]);
}

template <typename T> bool ecs::IEntity::has() const
{
    if (_components.empty())
        return (false);
    unsigned int id = ecs::TemplateComponent<T>::getId();
    if (id < _components.size() && _components[id])
        return (true);
    else
        return (false);
}

template <typename T> void ecs::IEntity::remove()
{
    if (has<T>() == false)
        std::cout << "Component not found" << std::endl;
    delete _components[ecs::TemplateComponent<T>::getId()];
}

template <typename T, typename... U> void ecs::IEntity::add(U &&...args)
{
    unsigned int id = ecs::TemplateComponent<T>::getId();
    if (id >= _components.size())
        _components.resize(id + 1);
    _components[id] = new T(std::forward<U>(args)...);
}
