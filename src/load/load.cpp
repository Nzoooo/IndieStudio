/*
** EPITECH PROJECT, 2022
** Project
** File description:
** load
*/

#include "load.hpp"
#include "ECS/Components/ComponentMovable.hpp"
#include "ECS/Components/ComponentTransform.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
extern "C"
{
#include <sys/stat.h>
}

template <typename T>
T getMember(std::ifstream &file, std::string member)
{
    T type;
    std::string line;

    while (std::getline(file, line)) {
        if (line == "\t\t}")
            break;
        // Skip tabulations
        line = line.substr(std::count(line.begin(), line.end(), '\t'));
        if (line.find(member) != std::string::npos) {
            //type = static_cast<T>(line);
            break;
        }
    }
    return type;
}

ecs::IEntity Load::loadEntity(std::ifstream &file)
{
    ecs::IEntity *entity = new ecs::IEntity();
    std::string line;

    while (getline(file, line)) {
        if (line == "\t}")
            break;
        if (line == "\t\tComponentMovable {") {
            entity->add<ComponentMovable>(getMember<ComponentMovable::Direction>(file, "dir"), getMember<int>(file, "speed"), getMember<bool>(file, "ableToMove"));
        }
    }
    return (*entity);
}

ecs::Core Load::loadFile(void)
{
    std::ifstream file(FILEPATH);
    ecs::Core core;
    struct stat st;
    size_t num_entity = 0;
    int checked_file = 0;

    if (stat(FILEPATH, &st) != 0)
        throw /* Can't open file */;
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            if (checked_file == 0 && std::to_string(st.st_mtime) != line)
                throw /* Le monsieur a triché en modifiant le ficher save */;
            checked_file = 1;
            if (line == "Entities [") {
                while (getline(file, line)) {
                    if (line == "]")
                        break;
                    if (line == std::string("\tEntity[" + std::to_string(num_entity) + "] {")) {
                        ecs::IEntity entity = loadEntity(file);
                        core.addEntity(&entity);
                        num_entity++;
                    }
                }
            }
        }
    }
    std::cout << "Loaded " << num_entity << " entities" << std::endl;
    return core;
}
