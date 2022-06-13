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

ecs::IEntity *Load::loadEntity(std::ifstream &file)
{
    ecs::IEntity *entity = new ecs::IEntity();
    std::string line;

    while (getline(file, line)) {
        if (line == "\t}")
            break;
        line = removeTabs(line);
        if (line == "ComponentMovable {")
            addComponentMovable(file, entity);
        if (line == "ComponentTransform {")
            addComponentTransform(file, entity);
        if (line == "ComponentKillable {")
            addComponentKillable(file, entity);
    }
    return (entity);
}

ecs::Core Load::loadFile(void)
{
    std::ifstream file(FILEPATH);
    ecs::Core core;
    struct stat st;
    std::string line;
    size_t num_entity = 0;
    int checked_file = 0;

    if (stat(FILEPATH, &st) != 0)
        throw std::exception();
    if (!file.is_open())
        throw std::exception();
    while (getline(file, line)) {
        if (checked_file == 0 && std::to_string(st.st_mtime) != line)
            throw std::exception();
        checked_file = 1;
        if (line == "Entities [") {
            while (getline(file, line)) {
                if (line == "]")
                    break;
                if (line == std::string("\tEntity[" + std::to_string(num_entity) + "] {")) {
                    ecs::IEntity *entity = loadEntity(file);
                    core.addEntity(entity);
                    num_entity++;
                }
            }
        }
    }
    return core;
}
