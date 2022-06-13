/*
** EPITECH PROJECT, 2022
** Project
** File description:
** save
*/

#include "save.hpp"
#include "ECS/Components/ComponentClickable.hpp"
#include "ECS/Components/ComponentCollider.hpp"
#include "ECS/Components/ComponentDrawable.hpp"
#include "ECS/Components/ComponentDroppable.hpp"
#include "ECS/Components/ComponentExplodable.hpp"
#include "ECS/Components/ComponentKillable.hpp"
#include "ECS/Components/ComponentMovable.hpp"
#include "ECS/Components/ComponentPickable.hpp"
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
    _file << std::time(nullptr) << std::endl;
    _file << "Entities [" << std::endl;
    for (auto &entity : core.getEntities()) {
        _file << "\tEntity[" << i << "] {" << std::endl;
        saveEntity(*entity);
        _file << "\t}" << std::endl;
        i++;
    }
    _file << "]" << std::endl;
}

void Save::saveEntity(ecs::IEntity &entity)
{
    if (entity.has<ComponentClickable>()) {
        auto component_data = dynamic_cast<ComponentClickable *>(entity.get<ComponentClickable>());
        _file << "\t\tComponentClickable {" << std::endl;
        _file << "\t\t\tableToBeClicked: 1" << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentCollider>()) {
        auto component_data = dynamic_cast<ComponentCollider *>(entity.get<ComponentCollider>());
        _file << "\t\tComponentCollider {" << std::endl;
        _file << "\t\t\tableToCollide: 1" << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentDrawable>()) {
        auto component_data = dynamic_cast<ComponentDrawable *>(entity.get<ComponentDrawable>());
        _file << "\t\tComponentDrawable {" << std::endl;
        _file << "\t\t\tisDrawable2D: " << component_data->getIsDrawable2D() << "," << std::endl;
        _file << "\t\t\tisDrawable3D: " << component_data->getIsDrawable3D() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentDroppable>()) {
        auto component_data = dynamic_cast<ComponentDroppable *>(entity.get<ComponentDroppable>());
        _file << "\t\tComponentDroppable {" << std::endl;
        _file << "\t\t\tableToBeDrawn: 1" << std::endl;
        _file << "\t\t}" << std::endl;
    }
}

void Save::eraseSave(void)
{
    std::ofstream clear_file;

    clear_file.open(FILEPATH, std::ofstream::out | std::ofstream::trunc);
    clear_file.close();
}
