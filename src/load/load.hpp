/*
** EPITECH PROJECT, 2022
** Project
** File description:
** load
*/

#ifndef LOAD_HPP_
#define LOAD_HPP_

#include "core/core.hpp"

#include <fstream>

#define FILEPATH "save.txt"

class Load {
  public:
    ecs::Core loadFile(void);
    ecs::IEntity *loadEntity(std::ifstream &file);
};

#endif /* !LOAD_HPP_ */
