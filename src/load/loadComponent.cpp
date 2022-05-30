/*
** EPITECH PROJECT, 2022
** Project
** File description:
** loadComponent
*/

#include "load.hpp"
#include "loadComponent.hpp"

std::string removeTabs(std::string line)
{
    std::string result = "";

    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] != '\t')
            result += line[i];
    }
    return result;
}

template <typename T> T getMember(std::ifstream &file, std::string member)
{
    std::string line;

    while (std::getline(file, line)) {
        if (line == "\t\t}")
            break;
        line = removeTabs(line);
        if (line.find(member) != std::string::npos) {
            line = line.substr(member.length() + 2, line.find(',') - member.length() - 2);
            return static_cast<T>(std::stoi(line));
        }
    }
    std::cout << member << " not found" << std::endl;
    throw /* Member not found */;
}

void addComponentMovable(std::ifstream &file, ecs::IEntity *entity)
{
    ComponentMovable::Direction dir = getMember<ComponentMovable::Direction>(file, "dir");
    int speed = getMember<int>(file, "speed");
    bool ableToMove = getMember<bool>(file, "ableToMove");

    try {
        entity->add<ComponentMovable>(dir, speed, ableToMove);
    } catch (std::exception &e) {
        std::cout << "ComponentMovable not found" << std::endl;
    }
}

void addComponentTransform(std::ifstream &file, ecs::IEntity *entity)
{
    size_t height = getMember<size_t>(file, "height");
    size_t width = getMember<size_t>(file, "width");
    int posX = getMember<int>(file, "posX");
    int posY = getMember<int>(file, "posY");

    try {
        entity->add<ComponentTransform>(height, width, posX, posY);
    } catch (std::exception &e) {
        std::cout << "ComponentMovable not found" << std::endl;
    }
}

void addComponentKillable(std::ifstream &file, ecs::IEntity *entity)
{
    bool ableToBeKilled = getMember<bool>(file, "ableToBeKilled");

    try {
        entity->add<ComponentKillable>(ableToBeKilled);
    } catch (std::exception &e) {
        std::cout << "ComponentMovable not found" << std::endl;
    }
}
