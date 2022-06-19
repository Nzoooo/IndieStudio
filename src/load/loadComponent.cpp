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

std::string getMember(std::ifstream &file, std::string member)
{
    std::string line;

    while (std::getline(file, line)) {
        if (line == "\t\t}")
            break;
        line = removeTabs(line);
        if (line.find(member) != std::string::npos) {
            line = line.substr(member.length() + 2, line.find(',') - member.length() - 2);
            return line;
        }
    }
    std::cout << member << " not found" << std::endl;
    throw std::exception();
}

void addComponentBombs(std::ifstream &file, ecs::IEntity *entity)
{
    std::size_t nbMaxBombs = std::stoi(getMember(file, "nbMaxBombs"));
    std::size_t nbCurrBombs = std::stoi(getMember(file, "nbCurrBombs"));

    try {
        entity->add<ComponentBombs>(nbMaxBombs, nbCurrBombs);
    } catch (std::exception &e) {
        std::cout << "ComponentBombs not found" << std::endl;
    }
}

void addComponentCollider(std::ifstream &file, ecs::IEntity *entity)
{
    bool ableToCollide = std::stoi(getMember(file, "ableToCollide"));
    std::string timeNonCollide = getMember(file, "timeNonCollide");

    try {
        if (ableToCollide)
            entity->add<ComponentCollider>();
    } catch (std::exception &e) {
        std::cout << "ComponentCollider not found" << std::endl;
    }
}

void addComponentControllable(std::ifstream &file, ecs::IEntity *entity)
{
    int gamepadID = std::stoi(getMember(file, "gamepadID"));

    try {
        entity->add<ComponentControllable>(gamepadID);
    } catch (std::exception &e) {
        std::cout << "ComponentControllable not found" << std::endl;
    }
}

void addComponentCube(std::ifstream &file, ecs::IEntity *entity)
{
    std::string str_pos = getMember(file, "pos");
    std::string str_size = getMember(file, "size");
    std::string str_color = getMember(file, "color");
    std::string str_texture = getMember(file, "texture");
    raylib::Texture texture;
    raylib::Vector3 pos = {};
    pos.x = std::stof(str_pos.substr(1, str_pos.find(';')));
    pos.y = std::stof(str_pos.substr(str_pos.find(';') + 1, str_pos.find(';', str_pos.find(';') + 1)));
    pos.z = std::stof(str_pos.substr(str_pos.find(';', str_pos.find(';') + 1) + 2, str_pos.find(')') - str_pos.find(')') - 2));
    raylib::Vector3 size = {std::stof(str_size.substr(1, str_size.find(';'))),
        std::stof(str_size.substr(str_size.find(';') + 1, str_size.find(')') - str_size.find(';') - 1)),
        std::stof(str_size.substr(str_size.find(';', str_size.find(';') + 1) + 2, str_size.find(')') - str_size.find(')') - 2))};
    raylib::Color color = {};
    color.r = std::stoi(str_color.substr(str_color.find('(') + 1, str_color.find(';') - 1));
    color.g = std::stoi(str_color.substr(str_color.find(';') + 1, str_color.find(';', str_color.find(';') + 1) - 1));
    color.b = std::stoi(str_color.substr(str_color.find(';', str_color.find(';') + 1) + 1, str_color.find(')') - 1));
    color.a = std::stoi(
        str_color.substr(str_color.find(';', str_color.find(';', str_color.find(';') + 1) + 1) + 1, str_color.find(')', str_color.find(')') + 1) - 1));

    try {
        texture.Load(str_texture);
        entity->add<ComponentCube>(pos, size, color, texture);
    } catch (std::exception &e) {
        std::cout << "ComponentCube not found" << std::endl;
    }
}

void addComponentDrawable(std::ifstream &file, ecs::IEntity *entity)
{
    bool isDrawable2D = std::stoi(getMember(file, "isDrawable2D"));
    bool isDrawable3D = std::stoi(getMember(file, "isDrawable3D"));

    try {
        entity->add<ComponentDrawable>(isDrawable2D, isDrawable3D);
    } catch (std::exception &e) {
        std::cout << "ComponentDrawable not found" << std::endl;
    }
}

void addComponentDroppable(std::ifstream &file, ecs::IEntity *entity)
{
    bool ableToBeDropped = std::stoi(getMember(file, "ableToBeDropped"));

    try {
        if (ableToBeDropped)
            entity->add<ComponentDroppable>();
    } catch (std::exception &e) {
        std::cout << "ComponentDroppable not found" << std::endl;
    }
}

void addComponentExplodable(std::ifstream &file, ecs::IEntity *entity)
{
    std::size_t blastRange = std::stoi(getMember(file, "blastRange"));

    try {
        entity->add<ComponentExplodable>(blastRange);
    } catch (std::exception &e) {
        std::cout << "ComponentExplodable not found" << std::endl;
    }
}

void addComponentKillable(std::ifstream &file, ecs::IEntity *entity)
{
    bool ableToBeKilled = std::stoi(getMember(file, "ableToBeKilled"));

    try {
        if (ableToBeKilled)
            entity->add<ComponentKillable>();
    } catch (std::exception &e) {
        std::cout << "ComponentKillable not found" << std::endl;
    }
}

void addComponentMovable(std::ifstream &file, ecs::IEntity *entity)
{
    ComponentMovable::Direction dir = static_cast<ComponentMovable::Direction>(stoi(getMember(file, "dir")));
    int speed = std::stoi(getMember(file, "speed"));

    try {
        entity->add<ComponentMovable>(dir, speed);
    } catch (std::exception &e) {
        std::cout << "ComponentMovable not found" << std::endl;
    }
}

void addComponentPickable(std::ifstream &file, ecs::IEntity *entity)
{
    bool ableToBePicked = std::stoi(getMember(file, "ableToBePicked"));

    try {
        if (ableToBePicked)
            entity->add<ComponentPickable>();
    } catch (std::exception &e) {
        std::cout << "ComponentPickable not found" << std::endl;
    }
}

void addComponentTexture(std::ifstream &file, ecs::IEntity *entity)
{
    std::string str_pos = getMember(file, "pos");
    std::string str_pos2 = getMember(file, "pos2");
    std::string str_oldPos = getMember(file, "oldPos");
    std::string texturePath = getMember(file, "texturePath");
    raylib::Vector2 pos = {
        std::stof(str_pos.substr(1, str_pos.find(';'))), std::stof(str_pos.substr(str_pos.find(';') + 1, str_pos.find(')') - str_pos.find(';') - 1))};
    raylib::Vector2 pos2 = {
        std::stof(str_pos2.substr(1, str_pos2.find(';'))), std::stof(str_pos2.substr(str_pos2.find(';') + 1, str_pos2.find(')') - str_pos2.find(';') - 1))};

    try {
        entity->add<ComponentTexture>(texturePath, pos, pos2);
    } catch (std::exception &e) {
        std::cout << "ComponentTexture not found" << std::endl;
    }
}

void addComponentTransform(std::ifstream &file, ecs::IEntity *entity)
{
    std::size_t height = std::stoi(getMember(file, "height"));
    std::size_t width = std::stoi(getMember(file, "width"));
    int posX = std::stoi(getMember(file, "posX"));
    int posY = std::stoi(getMember(file, "posY"));

    try {
        entity->add<ComponentTransform>(height, width, posX, posY);
    } catch (std::exception &e) {
        std::cout << "ComponentTransform not found" << std::endl;
    }
}

void addComponentTransparency(std::ifstream &file, ecs::IEntity *entity)
{
    std::size_t transparency = std::stoi(getMember(file, "transparency"));

    try {
        entity->add<ComponentTransparency>(transparency);
    } catch (std::exception &e) {
        std::cout << "ComponentTransparency not found" << std::endl;
    }
}
