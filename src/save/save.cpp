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
    if (entity.has<ComponentBombs>()) {
        auto component_data = dynamic_cast<ComponentBombs *>(entity.get<ComponentBombs>());
        _file << "\t\tComponentBombs {" << std::endl;
        _file << "\t\t\tnbMaxBombs: " << component_data->getNbMaxBombs() << "," << std::endl;
        _file << "\t\t\tnbCurrBombs: " << component_data->getNbCurrBombs() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentCollider>()) {
        _file << "\t\tComponentCollider {" << std::endl;
        _file << "\t\t\tableToCollide: 1" << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentControllable>()) {
        auto component_data = dynamic_cast<ComponentControllable *>(entity.get<ComponentControllable>());
        _file << "\t\tComponentControllable {" << std::endl;
        _file << "\t\t\tgamepadID: " << component_data->getGamepadId() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentCube>()) {
        auto component_data = dynamic_cast<ComponentCube *>(entity.get<ComponentCube>());
        _file << "\t\tComponentCube {" << std::endl;
        _file << "\t\t\tpos: " << component_data->getPos() << "," << std::endl;
        _file << "\t\t\tsize: " << component_data->getSize() << "," << std::endl;
        _file << "\t\t\tcolor: " << component_data->getColor() << std::endl;
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
        _file << "\t\tComponentDroppable {" << std::endl;
        _file << "\t\t\tableToBeDropped: 1" << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentExplodable>()) {
        auto component_data = dynamic_cast<ComponentExplodable *>(entity.get<ComponentExplodable>());
        _file << "\t\tComponentExplodable {" << std::endl;
        _file << "\t\t\tblastRange: " << component_data->getBlastRange() << "," << std::endl;
        _file << "\t\t\tableToExplode: " << component_data->getAbleToExplode() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentKillable>()) {
        _file << "\t\tComponentKillable {" << std::endl;
        _file << "\t\t\tableToBeKilled: 1" << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentMesh>()) {
        auto component_data = dynamic_cast<ComponentMesh *>(entity.get<ComponentMesh>());
        _file << "\t\tComponentMesh {" << std::endl;
        _file << "\t\t\tinitialPos: " << component_data->getPos() << "," << std::endl;
        _file << "\t\t\tsize: " << component_data->getSize() << "," << std::endl;
        _file << "\t\t\tcolor: " << component_data->getColor() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentMovable>()) {
        auto component_data = dynamic_cast<ComponentMovable *>(entity.get<ComponentMovable>());
        _file << "\t\tComponentMovable {" << std::endl;
        _file << "\t\t\tdir: " << component_data->getDirection() << "," << std::endl;
        _file << "\t\t\tspeed: " << component_data->getSpeed() << "," << std::endl;
        _file << "\t\t\tableToMove: " << component_data->getAbleToMove() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentPickable>()) {
        _file << "\t\tComponentPickable {" << std::endl;
        _file << "\t\t\tableToBePicked: 1" << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentRectangle>()) {
        auto component_data = dynamic_cast<ComponentRectangle *>(entity.get<ComponentRectangle>());
        _file << "\t\tComponentRectangle {" << std::endl;
        _file << "\t\t\tpos: " << component_data->getPos() << "," << std::endl;
        _file << "\t\t\tsize: " << component_data->getSize() << "," << std::endl;
        _file << "\t\t\tcolor: " << component_data->getColor() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentTexture>()) {
        auto component_data = dynamic_cast<ComponentTexture *>(entity.get<ComponentTexture>());
        _file << "\t\tComponentTexture {" << std::endl;
        _file << "\t\t\tpos: " << component_data->getPos() << "," << std::endl;
        _file << "\t\t\ttexturePath: " << component_data->getTexturePath() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentTransform>()) {
        auto component_data = dynamic_cast<ComponentTransform *>(entity.get<ComponentTransform>());
        _file << "\t\tComponentTransform {" << std::endl;
        _file << "\t\t\theight: " << component_data->getHeight() << "," << std::endl;
        _file << "\t\t\twidth: " << component_data->getWidth() << "," << std::endl;
        _file << "\t\t\tposX: " << component_data->getPosX() << "," << std::endl;
        _file << "\t\t\tposY: " << component_data->getPosY() << std::endl;
        _file << "\t\t}" << std::endl;
    }
    if (entity.has<ComponentTransparency>()) {
        auto component_data = dynamic_cast<ComponentTransparency *>(entity.get<ComponentTransparency>());
        _file << "\t\tComponentTransparency {" << std::endl;
        _file << "\t\t\ttransparency: " << component_data->getTransparency() << std::endl;
        _file << "\t\t}" << std::endl;
    }
}

void Save::eraseSave(void)
{
    std::ofstream clear_file;

    clear_file.open(FILEPATH, std::ofstream::out | std::ofstream::trunc);
    clear_file.close();
}
