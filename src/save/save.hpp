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

#define FILEPATH "save.txt"

class Save {
  public:
    Save();
    ~Save();
    void saveCore(ecs::Core &core);
    void saveEntity(ecs::IEntity &entity);
    void eraseSave(void);

  private:
    std::ofstream _file;
};

#endif /* !SAVE_HPP_ */
