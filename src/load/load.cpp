/*
** EPITECH PROJECT, 2022
** Project
** File description:
** load
*/

#include "load.hpp"
#include "loadComponent.hpp"

#include <iostream>
extern "C"
{
#include <sys/stat.h>
}

void Load::loadEntity(std::ifstream &file, ecs::IEntity *entity)
{
    std::string line;

    while (getline(file, line)) {
        if (line == "\t}" || line == "]" || line == "")
            break;
        line = removeTabs(line);
        if (line == "ComponentBombs {")
            addComponentBombs(file, entity);
        if (line == "ComponentCollider {")
            addComponentCollider(file, entity);
        if (line == "ComponentControllable {")
            addComponentControllable(file, entity);
        if (line == "ComponentCube {")
            addComponentCube(file, entity);
        if (line == "ComponentDrawable {")
            addComponentDrawable(file, entity);
        if (line == "ComponentDroppable {")
            addComponentDroppable(file, entity);
        if (line == "ComponentExplodable {")
            addComponentExplodable(file, entity);
        if (line == "ComponentKillable {")
            addComponentKillable(file, entity);
        if (line == "ComponentMovable {")
            addComponentMovable(file, entity);
        if (line == "ComponentPickable {")
            addComponentPickable(file, entity);
        if (line == "ComponentTexture {")
            addComponentTexture(file, entity);
        if (line == "ComponentTransform {")
            addComponentTransform(file, entity);
        if (line == "ComponentTransparency {")
            addComponentTransparency(file, entity);
    }
}

ecs::Core Load::loadFile(void)
{
    std::ifstream file(FILEPATH_LOAD);
    ecs::Core core;
    struct stat st;
    std::string line;
    std::size_t num_entity = 0;
    int checked_file = 0;

    if (stat(FILEPATH_LOAD, &st) != 0)
        throw std::exception();
    if (!file.is_open())
        throw std::exception();
    while (getline(file, line)) {
        if (checked_file == 0 && std::to_string(st.st_mtime) != line)
            throw std::exception();
        checked_file = 1;
        if (line == "Entities [") {
            while (getline(file, line)) {
                if (line == "]" || line == "" || line.find('}') != std::string::npos) {
                    return core;
                }
                if (line == std::string("\tEntity[" + std::to_string(num_entity) + "] {")) {
                    ecs::IEntity *entity = new ecs::IEntity;
                    loadEntity(file, entity);
                    core.addEntity(entity);
                    num_entity++;
                }
            }
        }
    }
    return core;
}
