#pragma once

#include <chrono>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include "Entities/IEntity.hpp"
#include "Systems/ISystem.hpp"

namespace ecs {
  class World {
  private:
    std::vector<ecs::IEntity *> _entities;
    std::vector<ecs::ISystem *> _systems;
    bool _stopped;
    std::queue<int> _garbage;
    std::chrono::nanoseconds _time;
    std::chrono::nanoseconds _sleepDuration;

  public:
    World();
    ~World();
    template<typename T> T* get();
    template<typename T, typename ... U> void add(U && ... args);
    template<typename T> bool has() const;
    template<typename T> void remove();

    void run();
    void update();
    void stop();

    unsigned int add(ecs::IEntity *e);
    ecs::IEntity *get(unsigned int const id);
    void remove(std::vector<ecs::IEntity*>::iterator it);
    void remove(unsigned int const i);
    std::vector<ecs::IEntity *>& getEntities();

    void setSleepDuration(std::chrono::nanoseconds const& sleepDuration);
    std::chrono::nanoseconds getSleepDuration() const;
  };
}

template<typename T>
T* ecs::World::get() {
  if (has<T>() == false)
    std::cout << "System not found" << std::endl;
  return static_cast<T *>(_systems[ecs::TemplateSystem<T>::getId()]);
}

template<typename T, typename ... U>
void ecs::World::add(U && ... args) {
  if (has<T>() == true)
    std::cout << "System already exists" << std::endl;

  unsigned int id = ecs::TemplateSystem<T>::getId();
  if (id >= _systems.size())
    _systems.resize(id + 1);
  _systems[id] = new T(std::forward<U>(args) ...);
}

template<typename T>
bool ecs::World::has() const {
  unsigned int id = ecs::TemplateSystem<T>::getId();
  return id < _systems.size() && _systems[id];
}

template<typename T>
void ecs::World::remove() {
  if (has<T>() == false)
    std::cout << "System not found" << std::endl;
  delete _systems[ecs::TemplateSystem<T>::getId()];
  _systems[ecs::TemplateSystem<T>::getId()] = 0;
}
