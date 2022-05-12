#include "World.hpp"

ecs::World::World() : _stopped(true), _sleepDuration(std::chrono::milliseconds(10)) {}

ecs::World::~World() {
  for (auto *it: _systems)
    delete it;
  for (auto *it: _entities)
    delete it;
}

void ecs::World::run() {
  _stopped = false;
  while (_stopped == false)
    this->update();
}

void ecs::World::update() {
  std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

  for (auto *it: _systems)
    it->update(*this);
  _time = std::chrono::steady_clock::now() - start;
  std::this_thread::sleep_for(_sleepDuration - _time);
}

void ecs::World::stop() {
  _stopped = true;
}

std::vector<ecs::IEntity *>& ecs::World::getEntities() {
  return _entities;
}

ecs::IEntity *ecs::World::get(unsigned int const i) {
  return _entities.at(i);
}

unsigned int ecs::World::add(ecs::IEntity *e) {
  if (_garbage.empty()) {
    _entities.push_back(e);
    return _entities.size() - 1;
  }
  else {
    unsigned int const id = _garbage.front();
    delete _entities[id];
    _entities[id] = e;
    _garbage.pop();
    return id;
  }
}

void ecs::World::remove(std::vector<ecs::IEntity*>::iterator it) {
  delete *it;
  *it = NULL;
}

void ecs::World::remove(unsigned int const i) {
  delete _entities[i];
}

void ecs::World::setSleepDuration(std::chrono::nanoseconds const& sleepDuration) {
  _sleepDuration = sleepDuration;
}

std::chrono::nanoseconds ecs::World::getSleepDuration() const {
  return _sleepDuration;
}
