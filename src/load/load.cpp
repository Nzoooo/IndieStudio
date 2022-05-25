/*
** EPITECH PROJECT, 2022
** Project
** File description:
** load
*/

#include "load.hpp"
#include "ECS/Components/ComponentMovable.hpp"
#include "ECS/Components/ComponentTransform.hpp"

#include <iostream>
extern "C"
{
#include <sys/stat.h>
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
                    if (line == std::string("\tEntity[" + std::to_string(num_entity) + "] {")) {
                        ecs::IEntity *entity = new ecs::IEntity();
                        num_entity++;
                    }
                    if (line == "]")
                        break;
                }
            }
        }
    }
    return core;
}
