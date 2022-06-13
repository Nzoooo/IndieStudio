/*
** EPITECH PROJECT, 2022
** Project
** File description:
** loadComponent
*/

#include "loadComponent.hpp"
#include "load.hpp"

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
    throw std::exception();
}

void addComponentClickable(std::ifstream &file, ecs::IEntity *entity)
{
    bool ableToBeClicked = getMember<bool>(file, "ableToBeClicked");

    try {
        if (ableToBeClicked)
            entity->add<ComponentClickable>();
    } catch (std::exception &e) {
        std::cout << "ComponentClickable not found" << std::endl;
    }
}

void addComponentCollider(std::ifstream &file, ecs::IEntity *entity)
{
    bool ableToCollide = getMember<bool>(file, "ableToCollide");

    try {
        if (ableToCollide)
            entity->add<ComponentCollider>();
    } catch (std::exception &e) {
        std::cout << "ComponentCollider not found" << std::endl;
    }
}

void addComponentDrawable(std::ifstream &file, ecs::IEntity *entity)
{
    bool isDrawable2D = getMember<bool>(file, "isDrawable2D");
    bool isDrawable3D = getMember<bool>(file, "isDrawable3D");

    try {
        entity->add<ComponentDrawable>(isDrawable2D, isDrawable3D);
    } catch (std::exception &e) {
        std::cout << "ComponentDrawable not found" << std::endl;
    }
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
        if (ableToBeKilled)
            entity->add<ComponentKillable>();
    } catch (std::exception &e) {
        std::cout << "ComponentMovable not found" << std::endl;
    }
}
