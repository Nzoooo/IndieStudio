#pragma once

#include <utility>
#include <vector>
#include <iostream>
#include "../Components/IComponent.hpp"

namespace ecs
{
    class IEntity {
    private:
        std::vector<ecs::IComponent *> _components;

    public:
        ~IEntity();
        template <typename T>
        T *get();
        template <typename T>
        bool has() const;
        template <typename T>
        void remove();
        template <typename T, typename... U>
        void add(U &&... args);
    };
} // namespace ecs

template <typename T>
T *ecs::IEntity::get()
{
    if (has<T>() == false)
        std::cout << "Component not found" << std::endl;
    return static_cast<T *>(_components[ecs::TemplateComponent<T>::getId()]);
}

template <typename T>
bool ecs::IEntity::has() const
{
    unsigned int id = ecs::TemplateComponent<T>::getId();
    if (id < _components.size() && _components[id])
        return (true);
    else
        return (false);
}

template <typename T>
void ecs::IEntity::remove()
{
    if (has<T>() == false)
        std::cout << "Component not found" << std::endl;
    delete _components[ecs::TemplateComponent<T>::getId()];
    _components[ecs::TemplateComponent<T>::getId()] = 0;
}

template<typename T, typename ... U>
void ecs::IEntity::add(U && ... args) {
  if (has<T>() == true)
    std::cout << "Component already exists" << std::endl;

  unsigned int id = ecs::TemplateComponent<T>::getId();
  if (id >= _components.size())
    _components.resize(id + 1);
  _components[id] = new T(std::forward<U>(args) ...);
}
