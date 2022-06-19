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

#define FILEPATH_LOAD "save.txt"

class Load {
  public:
    /// @brief Load the core from the file.
    /// @param ecs::Core The core to load.
    ecs::Core loadFile(void);

    /// @brief Load Components from the entity into the file.
    /// @param ecs::IEntity The entity to load.
    void loadEntity(std::ifstream &file, ecs::IEntity *entity);
};

#endif /* !LOAD_HPP_ */
