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

ecs::Core::~Core()
{
    for (auto *it : this->_systems)
        delete it;
    for (auto *it : this->_entities)
        delete it;
}

void ecs::Core::run()
{
    this->_stopped = false;
    while (this->_stopped == false)
        this->update();
}

void ecs::Core::update()
{
    for (auto *it : this->_systems)
        it->update(*this);
}

void ecs::Core::stop()
{
    this->_stopped = true;
}

std::vector<ecs::IEntity *> &ecs::Core::getEntities()
{
    return this->_entities;
}

ecs::IEntity *ecs::Core::getEntity(unsigned int const i)
{
    return this->_entities.at(i);
}

ecs::IEntity *ecs::Core::getEntity(std::string label)
{
    for (auto *it : this->_entities) {
        if (it->getLabel() == label)
            return it;
    }
    return nullptr;
}

unsigned int ecs::Core::addEntity(ecs::IEntity *e)
{
    this->_entities.push_back(e);
    return this->_entities.size() - 1;
}

void ecs::Core::removeEntityIterator(std::vector<ecs::IEntity *>::iterator it)
{
    delete *it;
}

void ecs::Core::removeEntity(unsigned int const i)
{
    delete this->_entities[i];
    this->_entities[i] = 0;
}

ecs::Scenes ecs::Core::getScene()
{
    return this->_scene;
}

void ecs::Core::setScene(ecs::Scenes scene)
{
    this->_scene = scene;
}

void ecs::Core::increaseNbButtons(int increment)
{
    this->_nbButtons += increment;
}

int ecs::Core::getNbButtons() const
{
    return this->_nbButtons;
}

ecs::GameStartMode ecs::Core::getStartMode() const
{
    return this->_start_mode;
}

void ecs::Core::setStartMode(ecs::GameStartMode start_mode)
{
    this->_start_mode = start_mode;
}
