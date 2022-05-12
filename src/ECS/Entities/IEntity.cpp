#include "IEntity.hpp"

ecs::IEntity::~IEntity() {
  for (auto *it: _components)
    delete it;
}
