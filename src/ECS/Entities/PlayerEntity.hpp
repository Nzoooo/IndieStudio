/*
** EPITECH PROJECT, 2022
** ECS
** File description:
** PlayerEntity
*/

#ifndef PLAYERENTITY_HPP_
#define PLAYERENTITY_HPP_

#include <string>
#include "IEntity.hpp"

class PlayerEntity : public ecs::IEntity {
  public:
    PlayerEntity();
    ~PlayerEntity();

  private:
    std::string _name;
};

#endif /* !PLAYERENTITY_HPP_ */
