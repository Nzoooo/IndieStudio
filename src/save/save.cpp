/*
** EPITECH PROJECT, 2022
** Project
** File description:
** save
*/

#include "save.hpp"
#include "ECS/Components/ComponentMovable.hpp"
#include "ECS/Components/ComponentTransform.hpp"

#include <iostream>

Save::Save()
{
    _file.open(FILEPATH, std::ios::app);
}

Save::~Save()
{
    _file.close();
}

void Save::saveCore(ecs::Core &core)
{
    eraseSave();
    _file << "[Entities]" << std::endl;
    for (auto &entity : core.getEntities()) {
        saveEntity(*entity);
        _file << std::endl;
    }
}

void Save::saveEntity(ecs::IEntity &entity)
{
    if (entity.has<ComponentMovable>()) {
        auto component_data = dynamic_cast<ComponentMovable *>(entity.get<ComponentMovable>());
        _file << "\tComponentMovable: " << component_data->getDirection() << " "  << component_data->getSpeed() << " "  << component_data->getAbleToMove() << std::endl;
    }
    if (entity.has<ComponentTransform>()) {
        auto component_data = dynamic_cast<ComponentTransform *>(entity.get<ComponentTransform>());
        _file << "\tComponentTransform: " << component_data->getHeight() << " " << component_data->getWidth() << " "  << component_data->getPosX() << " "  << component_data->getPosY() << std::endl;
    }
}

void Save::eraseSave(void)
{
    std::ofstream clear_file;

    clear_file.open(FILEPATH, std::ofstream::out | std::ofstream::trunc);
    clear_file.close();
}