/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ecs
*/

#include "ecs.hpp"

ecs::Core::Core()
{
}

ecs::Core::~Core() {
  for (auto *it: this->_systems)
    delete it;
  for (auto *it: this->_entities)
    delete it;
}

void ecs::Core::run() {
  this->_stopped = false;
  while (this->_stopped == false)
    this->update();
}

void ecs::Core::update() {

  for (auto *it: this->_systems)
    it->update(*this);
}

void ecs::Core::stop() {
  this->_stopped = true;
}

std::vector<ecs::IEntity *>& ecs::Core::getEntities() {
  return this->_entities;
}

ecs::IEntity *ecs::Core::getEntity(unsigned int const i) {
  return this->_entities.at(i);
}

unsigned int ecs::Core::addEntity(ecs::IEntity *e) {
    this->_entities.push_back(e);
    return this->_entities.size() - 1;
}

void ecs::Core::removeEntityIterrator(std::vector<ecs::IEntity*>::iterator it) {
  delete *it;
}

void ecs::Core::removeEntity(unsigned int const i) {
  delete this->_entities[i];
}

std::vector<ecs::ISystem *>& ecs::Core::getSystems() {
  return this->_systems;
}

ecs::ISystem *ecs::Core::getSystem(unsigned int const i) {
  return this->_systems.at(i);
}

unsigned int ecs::Core::addSystem(ecs::ISystem *e) {
    this->_systems.push_back(e);
    return _entities.size() - 1;
}

void ecs::Core::removeSystemIterrator(std::vector<ecs::ISystem*>::iterator it) {
  delete *it;
}

void ecs::Core::removeSystem(unsigned int const i) {
  delete this->_systems[i];
}