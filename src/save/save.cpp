/*
** EPITECH PROJECT, 2022
** Project
** File description:
** save
*/

#include "save.hpp"
#include "ECS/Components/AllComponents.hpp"
#include "raylib/include/Color.hpp"
#include "raylib/include/Vector2.hpp"
#include "raylib/include/Vector3.hpp"

#include <cstdio>
#include <string>

Save::Save()
{
    _file.open(FILEPATH_SAVE, std::ios::app);
}

Save::~Save()
{
    _file.close();
}

void Save::saveCore(ecs::Core &core)
{
    std::size_t i = 0;

    eraseSave();
    _file << std::time(nullptr) << std::endl;
    _file << "Entities [" << std::endl;
    for (auto &entity : core.getEntities()) {
        if (saveEntity(*entity, i))
            i++;
    }
    _file << "]" << std::endl;
}

bool Save::saveEntity(ecs::IEntity &entity, std::size_t i)
{
    bool ret = false;

    if (entity.has<ComponentBombs>()) {
        auto component_data = dynamic_cast<ComponentBombs *>(entity.get<ComponentBombs>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentBombs {" << std::endl;
        _file << "\t\t\tnbMaxBombs: " << component_data->getNbMaxBombs() << "," << std::endl;
        _file << "\t\t\tnbCurrBombs: " << component_data->getNbCurrBombs() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentCollider>()) {
        auto component_data = dynamic_cast<ComponentCollider *>(entity.get<ComponentCollider>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentCollider {" << std::endl;
        _file << "\t\t\tableToCollide: 1," << std::endl;
        std::time_t t = std::chrono::system_clock::to_time_t(component_data->getTimeNonCollide());
        std::string ts = std::ctime(&t);
        ts.resize(ts.size() - 1);
        _file << "\t\t\ttimeNonCollide: " << ts << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentControllable>()) {
        auto component_data = dynamic_cast<ComponentControllable *>(entity.get<ComponentControllable>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentControllable {" << std::endl;
        _file << "\t\t\tgamepadID: " << component_data->getGamepadId() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    // We don't need to save indestructible walls
    if (entity.has<ComponentCube>()) {
        if (!entity.has<ComponentKillable>())
            return false;
        auto component_data = dynamic_cast<ComponentCube *>(entity.get<ComponentCube>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentCube {" << std::endl;
        _file << "\t\t\tpos: " << component_data->getPos() << "," << std::endl;
        _file << "\t\t\tsize: " << component_data->getSize() << "," << std::endl;
        _file << "\t\t\tcolor: " << component_data->getColor() << "," << std::endl;
        _file << "\t\t\ttexture: " << component_data->getTexturePath() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentDrawable>() && !entity.has<ComponentMesh>()) {
        auto component_data = dynamic_cast<ComponentDrawable *>(entity.get<ComponentDrawable>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentDrawable {" << std::endl;
        _file << "\t\t\tisDrawable2D: " << component_data->getIsDrawable2D() << "," << std::endl;
        _file << "\t\t\tisDrawable3D: " << component_data->getIsDrawable3D() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentDroppable>()) {
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentDroppable {" << std::endl;
        _file << "\t\t\tableToBeDropped: 1" << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentExplodable>()) {
        auto component_data = dynamic_cast<ComponentExplodable *>(entity.get<ComponentExplodable>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentExplodable {" << std::endl;
        _file << "\t\t\tblastRange: " << component_data->getBlastRange() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentKillable>()) {
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentKillable {" << std::endl;
        _file << "\t\t\tableToBeKilled: 1" << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentMovable>()) {
        auto component_data = dynamic_cast<ComponentMovable *>(entity.get<ComponentMovable>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentMovable {" << std::endl;
        _file << "\t\t\tdir: " << component_data->getDirection() << "," << std::endl;
        _file << "\t\t\tspeed: " << component_data->getSpeed() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentPickable>()) {
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentPickable {" << std::endl;
        _file << "\t\t\tableToBePicked: 1" << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentTexture>()) {
        auto component_data = dynamic_cast<ComponentTexture *>(entity.get<ComponentTexture>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentTexture {" << std::endl;
        _file << "\t\t\tpos: " << component_data->getPos() << "," << std::endl;
        _file << "\t\t\tpos2: " << component_data->getPos2() << "," << std::endl;
        _file << "\t\t\toldPos: " << component_data->getOldPos() << "," << std::endl;
        _file << "\t\t\ttexturePath: " << component_data->getPathOldTexture() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentTransform>()) {
        auto component_data = dynamic_cast<ComponentTransform *>(entity.get<ComponentTransform>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentTransform {" << std::endl;
        _file << "\t\t\theight: " << component_data->getHeight() << "," << std::endl;
        _file << "\t\t\twidth: " << component_data->getWidth() << "," << std::endl;
        _file << "\t\t\tposX: " << component_data->getPosX() << "," << std::endl;
        _file << "\t\t\tposY: " << component_data->getPosY() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (entity.has<ComponentTransparency>()) {
        auto component_data = dynamic_cast<ComponentTransparency *>(entity.get<ComponentTransparency>());
        if (ret == false)
            _file << "\tEntity[" << i << "] {" << std::endl;
        _file << "\t\tComponentTransparency {" << std::endl;
        _file << "\t\t\ttransparency: " << component_data->getTransparency() << std::endl;
        _file << "\t\t}" << std::endl;
        ret = true;
    }
    if (ret == true)
        _file << "\t}" << std::endl;
    return ret;
}

void Save::eraseSave(void)
{
    std::ofstream clear_file;

    clear_file.open(FILEPATH_SAVE, std::ofstream::out | std::ofstream::trunc);
    clear_file.close();
}
