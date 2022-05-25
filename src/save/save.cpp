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
    size_t i = 0;

    eraseSave();
    _file << "Entities [" << std::endl;
    for (auto &entity : core.getEntities()) {
        _file << "\tEntity[" << i << "] {" << std::endl;
        saveEntity(*entity);
        _file << "\t}" << std::endl;
        i++;
    }
    _file << "}" << std::endl;
    _file << std::time(nullptr) << std::endl;
}

void Save::saveEntity(ecs::IEntity &entity)
{
    if (entity.has<ComponentMovable>()) {
        auto component_data = dynamic_cast<ComponentMovable *>(entity.get<ComponentMovable>());
        _file << "\t\tComponentMovable {" << std::endl, _file << "\t\t\tdir: " << component_data->getDirection() << "," << std::endl;
        _file << "\t\t\tspeed: " << component_data->getSpeed() << "," << std::endl;
        _file << "\t\t\tableToMove: " << component_data->getAbleToMove() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentTransform>()) {
        auto component_data = dynamic_cast<ComponentTransform *>(entity.get<ComponentTransform>());
        _file << "\t\tComponentTransform {" << std::endl, _file << "\t\t\theight: " << component_data->getHeight() << "," << std::endl;
        _file << "\t\t\twidth: " << component_data->getWidth() << "," << std::endl;
        _file << "\t\t\tposX: " << component_data->getPosX() << "," << std::endl;
        _file << "\t\t\tposY: " << component_data->getPosY() << std::endl;
        _file << "\t\t}" << std::endl;
    }
}

void Save::eraseSave(void)
{
    std::ofstream clear_file;

    clear_file.open(FILEPATH, std::ofstream::out | std::ofstream::trunc);
    clear_file.close();
}