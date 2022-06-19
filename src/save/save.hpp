/*
** EPITECH PROJECT, 2022
** Project
** File description:
** save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include "ECS/Entities/IEntity.hpp"
#include "core/core.hpp"

#include <fstream>

#define FILEPATH_SAVE "save.txt"

class Save {
  public:
    Save();
    ~Save();
    /// @brief Save the core into the file.
    /// @param ecs::Core The core to save.
    void saveCore(ecs::Core &core);

    /// @brief Save Components from the entity into the file.
    /// @param ecs::IEntity The entity to save.
    bool saveEntity(ecs::IEntity &entity, std::size_t i);

    /// @brief Empty the file.
    void eraseSave(void);

  private:
    std::ofstream _file;
};

#endif /* !SAVE_HPP_ */
