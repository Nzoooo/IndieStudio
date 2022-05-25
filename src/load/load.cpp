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
extern "C"
{
    #include <sys/stat.h>
}

template <typename T> T getMember(std::ifstream &file, std::string member)
{
    std::string line;

    while (std::getline(file, line)) {
        if (line == "\t\t}")
            break;
        // Skip tabulations
        line = line.substr(std::count(line.begin(), line.end(), '\t'));
        if (line.find(member) != std::string::npos) {
            line = line.substr(member.length() + 2, line.find(',') - member.length() - 2);
            return static_cast<T>(std::stoi(line));
        }
    }
    std::cout << member << " not found" << std::endl;
    throw /* Member not found */;
}

ecs::IEntity *Load::loadEntity(std::ifstream &file)
{
    ecs::IEntity *entity = new ecs::IEntity();
    std::string line;

    while (getline(file, line)) {
        if (line == "\t}")
            break;
        line = line.substr(std::count(line.begin(), line.end(), '\t'));
        if (line == "ComponentMovable {") {
            ComponentMovable::Direction dir = getMember<ComponentMovable::Direction>(file, "dir");
            int speed = getMember<int>(file, "speed");
            bool ableToMove = getMember<bool>(file, "ableToMove");
            try {
                entity->add<ComponentMovable>(dir, speed, ableToMove);
                continue;
            } catch (std::exception &e) {
                std::cout << "ComponentMovable not found" << std::endl;
            }
        }
        if (line == "ComponentTransform {") {
            size_t height = getMember<size_t>(file, "height");
            size_t width = getMember<size_t>(file, "width");
            int posX = getMember<int>(file, "posX");
            int posY = getMember<int>(file, "posY");
            try {
                entity->add<ComponentTransform>(height, width, posX, posY);
                continue;
            } catch (std::exception &e) {
                std::cout << "ComponentMovable not found" << std::endl;
            }
        }
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
        throw /* Can't open file */;
    if (!file.is_open())
        throw /* Can't open file */;
    while (getline(file, line)) {
        if (checked_file == 0 && std::to_string(st.st_mtime) != line)
            throw /* File changed manually */;
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
